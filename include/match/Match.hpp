#pragma once

#include "MatchStatistics.hpp"
#include "national_team/NationalTeam.hpp"

/**
 * @brief Class representing a football match between two national teams.
 */
class Match
{
public:
    /**
             * @brief Constructor for Match class.
             *
             * @param new_date The date of the match.
             * @param new_stage The stage of the match (e.g., group stage, knockout stage).
             * @param new_national_team Array containing pointers to the two national teams participating in the match.
        */
    Match(std::string new_date, MatchStage new_stage,
          const std::array<std::shared_ptr<NationalTeam>, 2> &new_national_team);
    /**
     * @brief Simulates the course of the match.
     */
    void simulate();
    /**
     * @brief Displays the result of the match.
     */
    void showResult() const;
    /**
     * @brief Displays the squads of the teams.
     */
    void showSquads() const;
    /**
        * @brief Displays the match statistics.
    */
    void showStatistics() const;
    /**
     * @brief Displays information about the match.
     */
    void showInformation() const;
    /**
     * @brief Gets the stage of the match.
     *
     * @return The stage of the match.
     */
    [[nodiscard]] auto getStage() const -> MatchStage;
    /**
     * @brief Checks if the match has finished.
     *
     * @return true if the match has finished, false otherwise.
     */
    [[nodiscard]] auto isFinished() const -> bool;

private:
    [[nodiscard]] auto calculateOverallAddition() const -> std::pair<int, int>;
    void showStage() const;
    void startSimulation(int minutes);
    void simulateGoal();
    void simulateYellowCard();
    void simulateRedCard();
    void simulateInjury();
    void simulateSubstitution();
    [[nodiscard]] auto selectGoalScorer(int team_index) const -> std::shared_ptr<Player>;
    void selectWhoAssisted(int team_index, const std::shared_ptr<Player> &goal_scorer) const;//TODO implement
    void selectWhoGetsYellowCard(int team_index) const;
    void selectWhoGetsRedCard(int team_index) const;
    void saveCleanSheets() const;
    [[nodiscard]] static auto getPenalityResult() -> std::array<int, 2>;
    void assignPoints() const;
    void assignNextStageToWinner(std::array<int, 2> penalty_result) const;

    std::string date;
    MatchStage stage;
    std::array<std::shared_ptr<NationalTeam>, 2> national_teams;
    std::array<Squad, 2> squads;
    MatchStatistics statistics;
    std::pair<int, int> overall_addition;
    bool finished;
};
