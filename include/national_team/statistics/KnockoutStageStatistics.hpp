#pragma once

#include "Statistics.hpp"

#include <string>

/**
 * @brief Class representing statistics for a knockout stage in a tournament.
 */
class KnockoutStageStatistics final : public Statistics
{
public:
    /**
     * @brief Constructor for KnockoutStageStatistics class.
     */
    KnockoutStageStatistics();
    /**
     * @brief Sets the next stage of the knockout stage.
     */
    void setNextStage();
    /**
     * @brief Gets the current stage of the knockout stage.
     *
     * @return A string representing the current stage of the knockout stage.
     */
    [[nodiscard]] auto getStage() const -> std::string;

private:
    std::string stage;
};
