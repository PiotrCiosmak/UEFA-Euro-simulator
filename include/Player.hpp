#pragma once

#include "Injury.hpp"
#include "Nationality.hpp"

class Player
{
public:
    Player(std::string new_first_name, std::string new_last_name, int new_overall,
           const Injury &new_injury,
           Nationality new_nationality, int new_goals = 0, int new_assists = 0);
    auto getName() -> std::string;
    auto getNumberOfGoals() -> int;
    auto getNumberOfAssists() -> int;
    auto getNationality() -> Nationality;
    auto getInjury() -> Injury;

protected:
    std::string first_name;
    std::string last_name;
    int overall;
    Injury injury;
    Nationality nationality;
    int goals;
    int assists;
};