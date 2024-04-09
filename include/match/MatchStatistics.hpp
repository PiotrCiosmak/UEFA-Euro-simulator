#pragma once

#include <array>

class MatchStatistics
{
public:
    MatchStatistics();
    auto getGoals() -> std::array<int, 2>;
    void show() const;

private:
    std::array<int, 2> goals;
    std::array<int, 2> yellow_cards;
    std::array<int, 2> red_cards;
    std::array<int, 2> changes_available;
    constexpr static auto max_changes = 5;
};
