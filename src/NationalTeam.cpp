#include "NationalTeam.hpp"

#include <iostream>

NationalTeam::NationalTeam(const Nationality new_country_name, const int new_position_in_ranking): county_name{
        new_country_name
    },
    position_in_ranking{new_position_in_ranking}
{
}

void NationalTeam::addPlayer(std::shared_ptr<Player> player)
{
    players.push_back(player);
}

void NationalTeam::showInformation() const
{
    std::cout << "Country: " << countryToString(county_name) << std::endl;
    std::cout << "Position in UEFA ranking: " << std::to_string(position_in_ranking) << std::endl;
}

auto NationalTeam::getPositionInRanking() const -> int
{
    return position_in_ranking;
}
