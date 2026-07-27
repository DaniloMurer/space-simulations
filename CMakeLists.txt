cmake_minimum_required(VERSION 3.11)
project(space_sim C)

set(CMAKE_C_STANDARD 99)

add_executable(space_sim
    src/main.c
    src/physics/vector3.c
)

target_include_directories(space_sim PRIVATE 
    src
)

target_link_libraries(space_sim
    raylib
    m
    pthread
    dl
    rt
    X11
)