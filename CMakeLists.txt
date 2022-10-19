cmake_minimum_required(VERSION 3.22)
project(pong)

set(raylib_USE_STATIC_LIBS ON)
set(raylib_VERBOSE ON)

find_package(raylib REQUIRED)

add_executable(pong src/main.cpp src/ball.cpp src/paddle.cpp)

target_include_directories(pong PRIVATE ${raylib_INCLUDE_DIRS} include)
target_link_libraries(pong ${raylib_LIBRARIES})