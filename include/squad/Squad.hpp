#pragma once

#include "player/Player.hpp"

#include <memory>
#include <vector>

/**
 * @brief Class representing a squad of football players.
 */
class Squad
{
public:
    /**
     * @brief Constructor for Squad class.
     *
     * @param new_players A vector of shared pointers to players to be included in the squad.
     */
    explicit Squad(const std::vector<std::shared_ptr<Player>> &new_players);
    /**
     * @brief Sets up the squad by choosing players for each position and substitutes.
     */
    void setSquad();
    /**
     * @brief Displays the squad.
     */
    void show() const;
    /**
     * @brief Checks if the squad is set.
     *
     * @return true if the squad is set, false otherwise.
     */
    [[nodiscard]] auto isSquadSet() const -> bool;
    /**
     * @brief Calculates the overall rating of the squad.
     *
     * @return The overall rating of the squad.
     */
    [[nodiscard]] auto getOverall() const -> int;
    /**
     * @brief Gets all field players in the squad.
     *
     * @return An array of shared pointers to field players in the squad.
     */
    [[nodiscard]] auto getAllFieldPlayers() const -> std::array<std::shared_ptr<Player>, 10>;
    /**
     * @brief Gets all players in the squad, including substitutes.
     *
     * @return An array of shared pointers to all players in the squad.
     */
    [[nodiscard]] auto getAllPlayers() const -> std::array<std::shared_ptr<Player>, 11>;

private:
    void chooseFormation();
    void choosePlayersByPosition(Position position, std::vector<std::shared_ptr<Player>> &players_by_position);
    void printAllPlayersByPosition(Position position) const;
    [[nodiscard]] auto getTargetNumberOfPlayersByPosition(Position position) const -> int;
    void chooseSubstitutes();
    void printAllUnselectedPlayers() const;
    static void printPlayers(const std::string &position, const std::vector<std::shared_ptr<Player>> &players);
    [[nodiscard]] auto sumOveral(std::vector<std::shared_ptr<Player>> players) const -> int;

    std::vector<std::shared_ptr<Player>> players;
    std::string formation;
    std::vector<std::shared_ptr<Player>> goalkeeper;
    std::vector<std::shared_ptr<Player>> defenders;
    std::vector<std::shared_ptr<Player>> midfielders;
    std::vector<std::shared_ptr<Player>> attackers;
    std::vector<std::shared_ptr<Player>> substitutes;
    constexpr static auto target_substitutes_number = 5;
};
