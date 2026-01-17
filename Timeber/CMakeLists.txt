cmake_minimum_required(VERSION 4.1)
project(Timeber)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_executable(Timeber main.cpp)

target_link_libraries(Timeber
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        sfml-network
)