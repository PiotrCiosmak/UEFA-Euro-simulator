#pragma once

#include "Nationality.hpp"
#include "player/Player.hpp"
#include "MatchStage.hpp"
#include "squad/Squad.hpp"
#include "statistics/Statistics.hpp"

class NationalTeam
{
public:
    NationalTeam(Nationality new_country_name, int new_position_in_ranking);
    [[nodiscard]] NationalTeam getCountryName() const -> Nationality;
    [[nodiscard]] auto getPositionInRanking() const -> int;
    void showStatistics(MatchStage stage) const;

private:
    void loadPlayers();
    [[nodiscard]] auto getSquadPlayers() const -> std::vector<std::shared_ptr<Player>>;
    void showGroupStageStatistics() const;
    void showKnockoutStageStatistics() const;

    Nationality county_name;
    std::vector<Player> players;
    const int position_in_ranking;
    std::shared_ptr<Squad> squad;
    //TODO podczas awansu z grupy dodajemy pusty obiekt knockoutStastics
    std::vector<std::shared_ptr<Statistics>> statistics;
    constexpr static auto max_players = 26;
};
