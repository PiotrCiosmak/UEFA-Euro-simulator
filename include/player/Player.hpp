#pragma once

#include "Injury.hpp"
#include "Nationality.hpp"
#include "PlayerStatistics.hpp"
#include "Position.hpp"

/**
 * @brief Class representing a football player.
 */
class Player
{
public:
    /**
     * @brief Constructor for Player class.
     *
     * @param new_first_name The first name of the player.
     * @param new_last_name The last name of the player.
     * @param new_overall The overall rating of the player.
     * @param new_nationality The nationality of the player.
     * @param new_position The position of the player.
     */
    Player(std::string new_first_name, std::string new_last_name, int new_overall,
           Nationality new_nationality, Position new_position);
    /**
     * @brief Gets the full name of the player.
     *
     * @return The full name of the player.
     */
    [[nodiscard]] auto getName() const -> std::string;
    /**
     * @brief Gets the overall rating of the player.
     *
     * @return The overall rating of the player.
     */
    [[nodiscard]] auto getOverall() const -> int;
    /**
     * @brief Gets the statistics of the player.
     *
     * @return A reference to the PlayerStatistics object representing the statistics of the player.
     */
    [[nodiscard]] auto getStatistics() -> PlayerStatistics &;
    /**
     * @brief Gets the nationality of the player.
     *
     * @return The nationality of the player.
     */
    [[nodiscard]] auto getNationality() const -> Nationality;
    /**
     * @brief Gets the injury status of the player.
     *
     * @return The injury status of the player.
     */
    [[nodiscard]] auto getInjury() const -> Injury;
    /**
     * @brief Gets the position of the player.
     *
     * @return The position of the player.
     */
    [[nodiscard]] auto getPosition() const -> Position;

private:
    std::string first_name;
    std::string last_name;
    int overall;
    Injury injury;
    Nationality nationality;
    PlayerStatistics player_statistics;
    Position position;
};
