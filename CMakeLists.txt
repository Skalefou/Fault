cmake_minimum_required(VERSION 3.29)
project(Fault C)

set(CMAKE_C_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Fault src/main.c)

target_link_libraries(Fault ${SDL2_LIBRARIES})
