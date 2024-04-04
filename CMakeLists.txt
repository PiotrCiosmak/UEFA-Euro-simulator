cmake_minimum_required(VERSION 3.27)
project(euro_simulation)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

add_executable(euro_simulation main.cpp
        ${INCLUDE_DIR}/Injury.hpp src/Injury.cpp
        ${INCLUDE_DIR}/Nationality.hpp
        ${INCLUDE_DIR}/player/Player.hpp src/player/Player.cpp
        ${INCLUDE_DIR}/player/Goalkeeper.hpp src/player/Goalkeeper.cpp
        ${INCLUDE_DIR}/player/Defender.hpp src/player/Defender.cpp
        ${INCLUDE_DIR}/player/Midfielder.hpp src/player/Midfielder.cpp
        ${INCLUDE_DIR}/player/Attacker.hpp src/player/Attacker.cpp
)
