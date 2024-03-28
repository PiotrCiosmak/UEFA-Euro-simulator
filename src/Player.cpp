#include "Player.hpp"

#include <utility>

Player::Player(std::string new_first_name, std::string new_last_name, int new_overall,
               const Injury &new_injury,
               Nationality new_nationality, int new_goals, int new_assists) : first_name{std::move(new_first_name)},
                                                                              last_name{std::move(new_last_name)},
                                                                              overall{new_overall},
                                                                              injury{new_injury},
                                                                              nationality{new_nationality},
                                                                              goals{new_goals}, assists{new_assists}
{}

auto Player::getName() -> std::string
{
    return first_name + last_name;
}

auto Player::getNumberOfGoals() -> int
{
    return goals;
}

auto Player::getNumberOfAssists() -> int
{
    return assists;
}

auto Player::getNationality() -> Nationality
{
    return nationality;
}

auto Player::getInjury() -> Injury
{
    return injury;
}
