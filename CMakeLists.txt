cmake_minimum_required(VERSION 3.28)
project(restapi)
set(CMAKE_CXX_STANDARD 23)

find_package(fmt CONFIG REQUIRED)

add_executable(restapi main.cpp)

target_link_libraries(restapi PRIVATE fmt::fmt)
target_include_directories(restapi PRIVATE "${VCPKG_ROOT}/packages/cpp-httplib_x64-windows/include")