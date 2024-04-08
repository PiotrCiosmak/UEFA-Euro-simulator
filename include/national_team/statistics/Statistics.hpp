#pragma once

class Statistics
{
public:
    Statistics();
    [[nodiscard]] auto getMatchesPlayed() const -> int;
    [[nodiscard]] auto getWins() const -> int;
    [[nodiscard]] auto getDraws() const -> int;
    [[nodiscard]] auto getLoses() const -> int;
    [[nodiscard]] auto getGoalsScored() const -> int;
    [[nodiscard]] auto getGoalsConceded() const -> int;
    [[nodiscard]] auto getYellowCards() const -> int;
    [[nodiscard]] auto getRedCards() const -> int;

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
