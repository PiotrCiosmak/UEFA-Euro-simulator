#include "national_team/statistics/Statistics.hpp"

Statistics::Statistics(): matches_played{0}, wins{0}, draws{0}, loses{0}, goals_scored{0}, goals_conceded{0},
                          yellow_cards{0}, red_cards{0}
{
}

void Statistics::addMatch()
{
    matches_played++;
}

void Statistics::addWin()
{
    wins++;
}

void Statistics::addDraw()
{
    draws++;
}

void Statistics::addLose()
{
    loses++;
}

void Statistics::addGoalScored()
{
    goals_scored++;
}

void Statistics::addGoalConceded()
{
    goals_conceded++;
}

void Statistics::addYellowCard()
{
    yellow_cards++;
}

void Statistics::addRedCard()
{
    red_cards++;
}

auto Statistics::getMatchesPlayed() const -> int
{
    return matches_played;
}

auto Statistics::getWins() const -> int
{
    return wins;
}

auto Statistics::getDraws() const -> int
{
    return draws;
}

auto Statistics::getLoses() const -> int
{
    return loses;
}

auto Statistics::getGoalsScored() const -> int
{
    return goals_scored;
}

auto Statistics::getGoalsConceded() const -> int
{
    return goals_conceded;
}

auto Statistics::getYellowCards() const -> int
{
    return yellow_cards;
}

auto Statistics::getRedCards() const -> int
{
    return red_cards;
}
