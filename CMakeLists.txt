cmake_minimum_required(VERSION 3.10)
project(Fault C)

set(CMAKE_C_STANDARD 17)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/external)

add_executable(Fault src/main.c
        src/WindowManager.c
        include/WindowManager.h
        src/Game.c
        include/Game.h
        src/Renderer.c
        include/Renderer.h
        src/Texture.c
        include/Texture.h
        src/Graphics.c
        include/Graphics.h
        external/cJSON.c
        external/cJSON.h
)

target_link_libraries(Fault ${SDL2_LIBRARIES})
