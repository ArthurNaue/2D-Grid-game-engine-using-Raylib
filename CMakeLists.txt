cmake_minimum_required(VERSION 3.10)
project(main C)

set(CMAKE_C_STANDARD 99)

find_package(raylib REQUIRED)

add_executable(main src/main.c)
target_link_libraries(main raylib m)
