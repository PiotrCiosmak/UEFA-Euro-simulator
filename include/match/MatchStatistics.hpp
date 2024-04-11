#pragma once

#include <array>

class MatchStatistics
{
public:
    MatchStatistics();
    [[nodiscard]] auto getGoals() const -> std::array<int, 2>;
    [[nodiscard]] auto getAvailableChanges() const -> std::array<int, 2>;
    void homeScoreGoal();
    void awayScoreGoal();
    void homeGetYellowCard();
    void awayGetYellowCard();
    void homeGetRedCard();
    void awayGetRedCard();
    void homeMakeChange();
    void awayMakeChange();
    void show() const;

private:
    std::array<int, 2> goals;
    std::array<int, 2> yellow_cards;
    std::array<int, 2> red_cards;
    std::array<int, 2> changes_available;
    constexpr auto max_changes = 5;
};
