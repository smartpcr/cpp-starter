#pragma once

#include <nlohmann/json.hpp>
#include "user.h"

namespace models {

struct Project {
    std::string name;
    std::vector<User> users;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Project, name, users)

}