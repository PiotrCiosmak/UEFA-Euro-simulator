#pragma once

#include "Injury.hpp"
#include "Nationality.hpp"
#include "PlayerStatistics.hpp"
#include "Position.hpp"

class Player
{
public:
    Player(std::string new_first_name, std::string new_last_name, int new_overall,
           Nationality new_nationality, Position new_position);
    [[nodiscard]] auto getName() const -> std::string;
    [[nodiscard]] auto getOverall() const -> int;
    [[nodiscard]] auto getStatistics() -> PlayerStatistics&;
    [[nodiscard]] auto getNationality() const -> Nationality;
    [[nodiscard]] auto getInjury() const -> Injury;
    [[nodiscard]] auto getPosition() const -> Position;

private:
    std::string first_name;
    std::string last_name;
    int overall;
    Injury injury;
    Nationality nationality;
    PlayerStatistics player_statistics;
    Position position;
};
