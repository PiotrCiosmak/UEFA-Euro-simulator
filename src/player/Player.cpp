#include "player/Player.hpp"

#include <utility>

Player::Player(std::string new_first_name, std::string new_last_name, const int new_overall,
               const Nationality new_nationality) : first_name{std::move(new_first_name)},
                                                    last_name{std::move(new_last_name)},
                                                    overall{new_overall},
                                                    nationality{new_nationality},
                                                    goals{0}, assists{0}
{
}

auto Player::getName() const -> std::string
{
    return first_name + last_name;
}

auto Player::getNumberOfGoals() const -> int
{
    return goals;
}

auto Player::getNumberOfAssists() const -> int
{
    return assists;
}

auto Player::getNationality() const -> Nationality
{
    return nationality;
}

auto Player::getInjury() const -> Injury
{
    return injury;
}
