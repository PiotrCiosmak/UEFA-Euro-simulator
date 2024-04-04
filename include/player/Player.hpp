#pragma once

#include "Injury.hpp"
#include "Nationality.hpp"

class Player
{
public:
    Player(std::string new_first_name, std::string new_last_name, int new_overall,
           Nationality new_nationality);
    [[nodiscard]] auto getName() const -> std::string;
    [[nodiscard]] auto getNumberOfGoals() const -> int;
    [[nodiscard]] auto getNumberOfAssists() const -> int;
    [[nodiscard]] auto getNationality() const -> Nationality;
    [[nodiscard]] auto getInjury() const -> Injury;

protected:
    std::string first_name;
    std::string last_name;
    int overall;
    Injury injury;
    Nationality nationality;
    int goals;
    int assists;
};
