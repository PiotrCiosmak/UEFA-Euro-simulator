#pragma once

#include "Statistics.hpp"

/**
 * @brief Class representing statistics for a group stage in a tournament.
 */
class GroupStatistics final : public Statistics
{
public:
    /**
     * @brief Constructor for GroupStatistics class.
     */
    GroupStatistics();
    /**
     * @brief Adds points to the group statistics.
     *
     * @param gained_points The number of points gained.
     */
    void addPoints(int gained_points);
    /**
     * @brief Marks the group as promoted (advanced to the next stage).
     */
    void promote();
    /**
     * @brief Gets the total points of the group.
     *
     * @return The total points of the group.
     */
    [[nodiscard]] auto getPoints() const -> int;
    /**
     * @brief Checks if the group is promoted.
     *
     * @return true if the group is promoted, false otherwise.
     */
    [[nodiscard]] auto isPromoted() const -> bool;

private:
    int points;
    bool promoted;
};
