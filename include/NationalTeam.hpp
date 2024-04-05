#pragma once

#include "Nationality.hpp"
#include "player/Player.hpp"

#include <memory>
#include <vector>

class NationalTeam
{
public:
    NationalTeam(Nationality new_country_name, int new_position_in_ranking);
    void addPlayer(std::shared_ptr<Player> player);
    void showInformation() const;
    [[nodiscard]] auto getPositionInRanking() const -> int;

private:
    Nationality county_name;
    std::vector<std::shared_ptr<Player>> players;
    const int position_in_ranking;
    constexpr int max_players = 26;
};
