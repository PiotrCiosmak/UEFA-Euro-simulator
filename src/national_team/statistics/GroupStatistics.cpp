#include "national_team/statistics/GroupStatistics.hpp"

GroupStatistics::GroupStatistics(): points{0}, promoted{false}
{
}

void GroupStatistics::addPoints(const int gained_points)
{
    points += gained_points;
}

void GroupStatistics::promote()
{
    promoted = true;
}

auto GroupStatistics::getPoints() const -> int
{
    return points;
}

auto GroupStatistics::isPromoted() const -> bool
{
    return promoted;
}
