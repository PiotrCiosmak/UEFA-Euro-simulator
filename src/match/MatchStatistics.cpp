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

void MatchStatistics::show() const
{
    std::cout << "Home Team Statistics:" << std::endl;
    std::cout << "Goals: " << goals[0] << std::endl;
    std::cout << "Yellow Cards: " << yellow_cards[0] << std::endl;
    std::cout << "Red Cards: " << red_cards[0] << std::endl;
    std::cout << "Changes made: " << max_changes - changes_available[0] << std::endl;

    std::cout << std::endl;

    std::cout << "Away Team Statistics:" << std::endl;
    std::cout << "Goals: " << goals[1] << std::endl;
    std::cout << "Yellow Cards: " << yellow_cards[1] << std::endl;
    std::cout << "Red Cards: " << red_cards[1] << std::endl;
    std::cout << "Changes made: " << max_changes - changes_available[1] << std::endl;
}
