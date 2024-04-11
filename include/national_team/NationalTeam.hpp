#pragma once

#include "Nationality.hpp"
#include "player/Player.hpp"
#include "MatchStage.hpp"
#include "squad/Squad.hpp"
#include "statistics/GroupStatistics.hpp"
#include "statistics/KnockoutStageStatistics.hpp"

class NationalTeam
{
public:
    NationalTeam(Nationality new_country_name, int new_position_in_ranking);
    [[nodiscard]] auto getCountryName() const -> Nationality;
    [[nodiscard]] auto getPositionInRanking() const -> int;
    [[nodiscard]] auto getSquad() const -> std::shared_ptr<Squad>;
    void showStatistics(MatchStage stage) const;
    [[nodiscard]] auto getGroupStageStatistics() const ->std::shared_ptr<GroupStatistics>;
    [[nodiscard]] auto getKnockoutStageStatistics() const -> std::shared_ptr<KnockoutStageStatistics>;

private:
    void loadPlayers();
    [[nodiscard]] auto getSquadPlayers() const -> std::vector<std::shared_ptr<Player>>;
    void showGroupStageStatistics() const;
    void showKnockoutStageStatistics() const;

    Nationality county_name;
    std::vector<Player> players;
    const int position_in_ranking;
    std::shared_ptr<Squad> squad;
    //TODO after promotion add new KnockoutStatistics object to vector statistics
    std::vector<std::shared_ptr<Statistics>> statistics;
    constexpr static auto max_players = 26;
};
