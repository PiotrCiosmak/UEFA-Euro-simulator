cmake_minimum_required(VERSION 3.27)
project(euro_simulation)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include_directories(${INCLUDE_DIR})

add_executable(euro_simulation apps/main.cpp
        ${INCLUDE_DIR}/utils/TextUtils.hpp
        ${INCLUDE_DIR}/player/Injury.hpp src/player/Injury.cpp
        ${INCLUDE_DIR}/Nationality.hpp
        ${INCLUDE_DIR}/player/Player.hpp src/player/Player.cpp
        ${INCLUDE_DIR}/player/PlayerStatistics.hpp
        ${INCLUDE_DIR}/player/Position.hpp
        ${INCLUDE_DIR}/MatchStage.hpp
        ${INCLUDE_DIR}/squad/FormationsManager.hpp src/squad/FormationsManager.cpp
        ${INCLUDE_DIR}/squad/Squad.hpp src/squad/Squad.cpp
        ${INCLUDE_DIR}/Group.hpp src/Group.cpp
        ${INCLUDE_DIR}/national_team/NationalTeam.hpp src/national_team/NationalTeam.cpp
        ${INCLUDE_DIR}/national_team/statistics/Statistics.hpp src/national_team/statistics/Statistics.cpp
        ${INCLUDE_DIR}/national_team/statistics/GroupStatistics.hpp src/national_team/statistics/GroupStatistics.cpp
        ${INCLUDE_DIR}/national_team/statistics/KnockoutStageStatistics.hpp src/national_team/statistics/KnockoutStageStatistics.cpp
        ${INCLUDE_DIR}/Euro.hpp src/Euro.cpp
        ${INCLUDE_DIR}/Schedule.hpp src/Schedule.cpp
        ${INCLUDE_DIR}/match/Match.hpp src/match/Match.cpp
        ${INCLUDE_DIR}/match/MatchStatistics.hpp src/match/MatchStatistics.cpp
)
