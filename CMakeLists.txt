cmake_minimum_required(VERSION 3.28)
project(restapi)
set(CMAKE_CXX_STANDARD 23)

find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp util/logger.cpp api/host.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt spdlog::spdlog nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME} PRIVATE "${VCPKG_ROOT}/packages/cpp-httplib_x64-windows/include")