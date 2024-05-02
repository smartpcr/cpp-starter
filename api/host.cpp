#include "host.h"
#include "../util/logger.h"

bool hosts::Host::isAllowed(const std::string &ipaddr) {
    return allowedIps.find(ipaddr) != allowedIps.end();
}

void hosts::Host::run(httplib::Server &server, Loggable &loggable) {
    filterByIp(server, loggable);
    setupErrors(server, loggable);
    setupRoutes(server, loggable);
    std::string message = "server listening on " + ip + ":" + std::to_string(port);
    LOG_INFO(loggable, message.c_str());
    server.listen(ip.c_str(), port);
}

void hosts::Host::filterByIp(httplib::Server &server, Loggable &loggable) {
    server.set_logger([&loggable](auto &req, auto &res) {
        std::string logMessage = req.remote_addr + " " + req.method + " " + req.path;
        if (res.status != -1) {
            logMessage += " " + std::to_string(res.status);
        }
        LOG_INFO(loggable, logMessage.c_str());
        return logMessage;
    });

    server.set_pre_routing_handler([this, &loggable](const httplib::Request &req, httplib::Response &res) {
        if (!isAllowed(req.remote_addr)) {
            auto error = "Unauthorized: " + req.remote_addr;
            LOG_ERROR(loggable, error.c_str());
            res.status = 403;
            res.set_content(error, "text/plain");
            return httplib::Server::HandlerResponse::Handled;
        }

        return httplib::Server::HandlerResponse::Unhandled;
    });
}

void hosts::Host::setupErrors(httplib::Server &server, Loggable &loggable) {
    server.set_error_handler([&loggable](const httplib::Request &req, httplib::Response &res) {
        auto ipAddr = "IP:" + req.get_header_value("REMOTE_ADDR") + " ";
        auto methodAndPath = req.method + " " + req.path;
        auto status = " " + std::to_string(res.status) + "";
        auto logStr = ipAddr + methodAndPath + status;
        std::string error = "Error: " + std::to_string(res.status) + " - " + res.reason;
        LOG_ERROR(loggable, logStr.c_str());
    });
}

void hosts::Host::setupRoutes(httplib::Server &server, Loggable &loggable) {
    server.Get("/ping", [&loggable](const httplib::Request &req, httplib::Response &res) {
        LOG_INFO(loggable, "Ping");
        res.set_content("Pong", "text/plain");
    });

    server.Get("/health", [&loggable](const httplib::Request &req, httplib::Response &res) {
        LOG_INFO(loggable, "Health");
        res.set_content("Healthy", "text/plain");
    });
}