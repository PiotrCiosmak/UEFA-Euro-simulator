#pragma once

#include <array>

/**
 * @brief Class representing statistics of a football match.
 */
class MatchStatistics
{
public:
    /**
     * @brief Constructor for MatchStatistics class.
     */
    MatchStatistics();
    /**
     * @brief Gets the number of goals scored by each team.
     *
     * @return An array containing the number of goals scored by each team.
     */
    [[nodiscard]] auto getGoals() const -> std::array<int, 2>;
    /**
     * @brief Gets the number of available changes for each team.
     *
     * @return An array containing the number of available changes for each team.
     */
    [[nodiscard]] auto getAvailableChanges() const -> std::array<int, 2>;
    /**
     * @brief Records a goal scored by the home team.
     */
    void homeScoreGoal();
    /**
     * @brief Records a goal scored by the away team.
     */
    void awayScoreGoal();
    /**
     * @brief Records a yellow card shown to the home team.
     */
    void homeGetYellowCard();
    /**
     * @brief Records a yellow card shown to the away team.
     */
    void awayGetYellowCard();
    /**
     * @brief Records a red card shown to the home team.
     */
    void homeGetRedCard();
    /**
     * @brief Records a red card shown to the away team.
     */
    void awayGetRedCard();
    /**
     * @brief Records a substitution made by the home team.
     */
    void homeMakeChange();
    /**
     * @brief Records a substitution made by the away team.
     */
    void awayMakeChange();
    /**
     * @brief Displays the match statistics.
     */
    void show() const;

private:
    std::array<int, 2> goals;
    std::array<int, 2> yellow_cards;
    std::array<int, 2> red_cards;
    std::array<int, 2> changes_available;
    constexpr static int max_changes = 5;
};
