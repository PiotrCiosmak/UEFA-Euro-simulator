#pragma once

class Statistics
{
public:
    Statistics();
    void addMatch();
    void addWin();
    void addDraw();
    void addLose();
    void addGoalScored();
    void addGoalConceded();
    void addYellowCard();
    void addRedCard();
    [[nodiscard]] auto getMatchesPlayed() const -> int;
    [[nodiscard]] auto getWins() const -> int;
    [[nodiscard]] auto getDraws() const -> int;
    [[nodiscard]] auto getLoses() const -> int;
    [[nodiscard]] auto getGoalsScored() const -> int;
    [[nodiscard]] auto getGoalsConceded() const -> int;
    [[nodiscard]] auto getYellowCards() const -> int;
    [[nodiscard]] auto getRedCards() const -> int;
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
