#pragma once

#include <nlohmann/json.hpp>

namespace models {

struct User {
    std::string name;
    std::string email;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(User, name, email)

}