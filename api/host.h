#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <unordered_set>
#include <httplib.h>
#include "../util/logger.h"
#include "../util/config.h"

namespace hosts {
    class Host {
        public:
            Host(const Configuration &config) {
                ip = config.ip;
                port = config.port;
                allowedIps = config.allowedIps;
            }

            ~Host() = default;

            void run(httplib::Server &server, Loggable &loggable);

        private:
            void filterByIp(httplib::Server &server, Loggable &loggable);
            void setupErrors(httplib::Server &server, Loggable &loggable);
            void setupRoutes(httplib::Server &server, Loggable &loggable);
            bool isAllowed(const std::string &ipaddr);

            std::string ip;
            int port;
            std::unordered_set<std::string> allowedIps;
    };
}