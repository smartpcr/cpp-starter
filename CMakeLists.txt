cmake_minimum_required(VERSION 3.28)
project(restapi)
set(CMAKE_CXX_STANDARD 23)

find_package(fmt CONFIG REQUIRED)

add_executable(restapi main.cpp)

target_link_libraries(restapi PRIVATE fmt::fmt)