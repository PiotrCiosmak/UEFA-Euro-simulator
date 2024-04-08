#include "national_team/statistics/GroupStatistics.hpp"

GroupStatistics::GroupStatistics(): points{0}, promoted{false}
{
}

auto GroupStatistics::getPoints() const -> int
{
    return points;
}

auto GroupStatistics::isPromoted() const -> bool
{
    return promoted;
}
