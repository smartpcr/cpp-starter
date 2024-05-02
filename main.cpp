#include <fmt/core.h>
#include <httplib.h>
#include "logger.h"
#include "constant.h"

int main() {
    Loggable logger;
    Constant constant;

    LOG_INFO(logger, constant.message);
    httplib::Client client("http://example.com");
    auto res = client.Get("/");
    if (res) {
        std::string statusString = "Status: " + std::to_string(res->status);
        LOG_INFO(logger, statusString.c_str());
        for (const auto& [key, value] : res->headers) {
            std::string headerStr = key + ": " + value;
            LOG_INFO(logger, headerStr.c_str());
        }

        LOG_DEBUG(logger, res->body.c_str());
    } else {
        LOG_ERROR(logger, constant.errorMessage);
    }

    fmt::print("Hello, World!\n");
    return 0;
}