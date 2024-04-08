#pragma once

#include "Statistics.hpp"

#include <string>

class KnockoutStageStatistics final : public Statistics
{
public:
    KnockoutStageStatistics();
    void setNextStage();
    [[nodiscard]] auto getStage() const -> std::string;

private:
    std::string stage;
};
