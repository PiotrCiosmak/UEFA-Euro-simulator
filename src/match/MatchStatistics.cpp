#include "match/MatchStatistics.hpp"

#include <iostream>

MatchStatistics::MatchStatistics(): goals{0, 0}, yellow_cards{0, 0}, red_cards{0, 0},
                                    changes_available{max_changes, max_changes}
{
}

auto MatchStatistics::getGoals() -> std::array<int, 2>
{
    return goals;
}

void MatchStatistics::homeScoreGoal()
{
    goals.at(0) += 1;
}

void MatchStatistics::awayScoreGoal()
{
    goals.at(1) += 1;
}

void MatchStatistics::homeGetYellowCard()
{
    yellow_cards.at(0) += 1;
}

void MatchStatistics::awayGetYellowCard()
{
    yellow_cards.at(1) += 1;
}

void MatchStatistics::homeGetRedCard()
{
    red_cards.at(0) += 1;
}

void MatchStatistics::awayGetRedCard()
{
    red_cards.at(1) += 1;
}

auto MatchStatistics::homeMakeChange() -> bool
{
    if (max_changes - changes_available.at(0) > 0)
    {
        changes_available.at(0) -= 1;
        return true;
    }
    return false;
}

auto MatchStatistics::awayMakeChange() -> bool
{
    if (max_changes - changes_available.at(0) > 0)
    {
        changes_available.at(0) -= 1;
        return true;
    }
    return false;
}

void MatchStatistics::show() const
{
    std::cout << "Home Team Statistics:" << std::endl;
    std::cout << "Goals: " << goals.at(0) << std::endl;
    std::cout << "Yellow Cards: " << yellow_cards.at(0) << std::endl;
    std::cout << "Red Cards: " << red_cards.at(0) << std::endl;
    std::cout << "Changes made: " << max_changes - changes_available.at(0) << std::endl;

    std::cout << std::endl;

    std::cout << "Away Team Statistics:" << std::endl;
    std::cout << "Goals: " << goals.at(1) << std::endl;
    std::cout << "Yellow Cards: " << yellow_cards.at(1) << std::endl;
    std::cout << "Red Cards: " << red_cards.at(1) << std::endl;
    std::cout << "Changes made: " << max_changes - changes_available.at(1) << std::endl;
}