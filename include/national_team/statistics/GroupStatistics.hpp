#pragma once

#include "Statistics.hpp"

class GroupStatistics final : public Statistics
{
public:
    GroupStatistics();
    void addPoints(int gained_points);
    void promote();
    [[nodiscard]] auto getPoints() const -> int;
    [[nodiscard]] auto isPromoted() const -> bool;

private:
    int points;
    bool promoted;
};
