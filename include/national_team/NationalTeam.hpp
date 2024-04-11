#pragma once

#include "MatchStage.hpp"
#include "squad/Squad.hpp"
#include "statistics/GroupStatistics.hpp"
#include "statistics/KnockoutStageStatistics.hpp"

/**
 * @brief Class representing a national football team.
 */
class NationalTeam
{
public:
    /**
     * @brief Constructor for NationalTeam class.
     *
     * @param new_country_name The nationality of the team.
     * @param new_position_in_ranking The position of the team in the ranking.
     */
    NationalTeam(Nationality new_country_name, int new_position_in_ranking);
    /**
     * @brief Gets the nationality of the team.
     *
     * @return The nationality of the team.
     */
    [[nodiscard]] auto getCountryName() const -> Nationality;
    /**
     * @brief Gets the position of the team in the ranking.
     *
     * @return The position of the team in the ranking.
     */
    [[nodiscard]] auto getPositionInRanking() const -> int;
    /**
     * @brief Gets the squad of the team.
     *
     * @return A shared pointer to the squad of the team.
     */
    [[nodiscard]] auto getSquad() const -> std::shared_ptr<Squad>;
    /**
     * @brief Displays the statistics of the team for a specific stage of the tournament.
     *
     * @param stage The stage of the tournament.
     */
    void showStatistics(MatchStage stage) const;
    /**
     * @brief Gets the statistics of the team for the group stage.
     *
     * @return A shared pointer to the group stage statistics of the team.
     */
    [[nodiscard]] auto getGroupStageStatistics() const -> std::shared_ptr<GroupStatistics>;
    /**
     * @brief Gets the statistics of the team for the knockout stage.
     *
     * @return A shared pointer to the knockout stage statistics of the team.
     */
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
