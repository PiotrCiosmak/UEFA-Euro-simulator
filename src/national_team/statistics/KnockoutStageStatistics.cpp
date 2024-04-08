#include "national_team/statistics/KnockoutStageStatistics.hpp"

#include <iostream>

KnockoutStageStatistics::KnockoutStageStatistics() : stage{"1/8"}
{
}

void KnockoutStageStatistics::setNextStage()
{
    if (stage == "1/8")
    {
        stage = "1/4";
    }
    else if (stage == "1/4")
    {
        stage = "1/2";
    }
    else if (stage == "1/2")
    {
        stage = "final";
    }
    else
    {
        std::cerr << "Error: Unable to set next stage after stage final." << std::endl;
        exit(1);
    }
}

auto KnockoutStageStatistics::getStage() const -> std::string
{
    return stage;
}
