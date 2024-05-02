#pragma once

#include <string>
#include <unordered_set>

struct Configuration {
    std::string ip;
    int port;
    std::unordered_set<std::string> allowedIps;
};
