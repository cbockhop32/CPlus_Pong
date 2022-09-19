cmake_minimum_required(VERSION 3.10.2)
set(CMAKE_CXX_STANDARD 11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)


project(pong VERSION 1.0)

find_package(raylib 2.5.0 REQUIRED)
INCLUDE_DIRECTORIES(${raylib_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp game_functions.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} LINK_PUBLIC raylib)
