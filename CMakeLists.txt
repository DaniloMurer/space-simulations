cmake_minimum_required(VERSION 3.11)
project(space_sim C)

set(CMAKE_C_STANDARD 99)

add_executable(space_sim main.c)

target_link_libraries(space_sim
    raylib
    m
    pthread
    dl
    rt
    X11
)