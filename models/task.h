#pragma once

#include <nlohmann/json.hpp>
#include "user.h"

namespace models {

struct Task {
    std::string description;
    User assignedUser;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Task, description, assignedUser)

}