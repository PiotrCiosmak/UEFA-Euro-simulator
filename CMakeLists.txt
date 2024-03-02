cmake_minimum_required(VERSION 3.28)
project(euro_simulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(euro_simulation main.cpp
        src/Player.cpp)
