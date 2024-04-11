#pragma once

/**
 * @brief Class representing statistics for a team in a tournament.
 */
class Statistics
{
public:
    /**
     * @brief Constructor for Statistics class.
     */
    Statistics();
    /**
     * @brief Increments the number of matches played.
     */
    void addMatch();
    /**
     * @brief Increments the number of wins.
     */
    void addWin();
    /**
     * @brief Increments the number of draws.
     */
    void addDraw();
    /**
     * @brief Increments the number of loses.
     */
    void addLose();
    /**
     * @brief Increments the number of goals scored.
     */
    void addGoalScored();
    /**
     * @brief Increments the number of goals conceded.
     */
    void addGoalConceded();
    /**
     * @brief Increments the number of yellow cards received.
     */
    void addYellowCard();
    /**
     * @brief Increments the number of red cards received.
     */
    void addRedCard();
    /**
     * @brief Gets the number of matches played.
     *
     * @return The number of matches played.
     */
    [[nodiscard]] auto getMatchesPlayed() const -> int;
    /**
     * @brief Gets the number of wins.
     *
     * @return The number of wins.
     */
    [[nodiscard]] auto getWins() const -> int;
    /**
     * @brief Gets the number of draws.
     *
     * @return The number of draws.
     */
    [[nodiscard]] auto getDraws() const -> int;
    /**
     * @brief Gets the number of loses.
     *
     * @return The number of loses.
     */
    [[nodiscard]] auto getLoses() const -> int;
    /**
     * @brief Gets the number of goals scored.
     *
     * @return The number of goals scored.
     */
    [[nodiscard]] auto getGoalsScored() const -> int;
    /**
     * @brief Gets the number of goals conceded.
     *
     * @return The number of goals conceded.
     */
    [[nodiscard]] auto getGoalsConceded() const -> int;
    /**
     * @brief Gets the number of yellow cards received.
     *
     * @return The number of yellow cards received.
     */
    [[nodiscard]] auto getYellowCards() const -> int;
    /**
     * @brief Gets the number of red cards received.
     *
     * @return The number of red cards received.
     */
    [[nodiscard]] auto getRedCards() const -> int;
    /**
     * @brief Virtual destructor for Statistics class.
     */
    virtual ~Statistics() = default;

protected:
    int matches_played;
    int wins;
    int draws;
    int loses;
    int goals_scored;
    int goals_conceded;
    int yellow_cards;
    int red_cards;
};
