#include <fmt/core.h>
#include <httplib.h>
#include <fstream>
#include "util/logger.h"
#include "util/constant.h"
#include "util/config.h"
#include "api/host.h"

void loadConfig(const std::string &path, Loggable &logger, Configuration &config) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Could not open file: " + path);
    }

    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    nlohmann::json json = nlohmann::json::parse(str);
    LOG_INFO(logger, json.dump().c_str());

    config.ip = json.value("ip", "127.0.0.1");
    config.port = json.value("port", 8080);
    config.allowedIps = json.value("allowedIps", std::unordered_set<std::string>());
}

void start(Configuration &config, Loggable &logger) {
    hosts::Host host(config);
    httplib::Server server;
    host.run(server, logger);
}

bool ping(Configuration &config) {
    httplib::Client client(fmt::format("http://{}:{}", config.ip, config.port));
    auto res = client.Get("/ping");
    if (res && res->status == 200) {
        return true;
    }
    
    return false;
}

int main() {
    Loggable logger;
    Constant constant;
    LOG_INFO(logger, constant.message);
    
    Configuration config;
    std::string configFilePath = "restapi.json";
    std::string loadingConfigMsg = "Loading configuration from " + configFilePath;
    LOG_INFO(logger, loadingConfigMsg.c_str());
    loadConfig(configFilePath.c_str(), logger, config);

    std::thread serverThread(start, std::ref(config), std::ref(logger));
    serverThread.detach();

    fmt::print("API server started...\n");

    constexpr int idleTime = 5;
    auto status = ping(config);
    while (status) {
        std::this_thread::sleep_for(std::chrono::seconds(idleTime));
        status = ping(config);
    }

    return 0;
}
