#pragma once

#include <memory>
#include <vector>

#include "player/Player.hpp"

class Squad
{
public:
    explicit Squad(const std::vector<std::shared_ptr<Player>> &new_players);
    void setSquad();
    void showSquad() const;
    [[nodiscard]] auto isSquadSet() const -> bool;

private:
    void chooseFormation();
    void choosePlayersByPosition(Position position, std::vector<std::shared_ptr<Player>> &players_by_position);
    void printAllPlayersByPosition(Position position) const;
    [[nodiscard]] auto getTargetNumberOfPlayersByPosition(Position position) const -> int;
    void chooseSubstitutes();
    void printAllUnselectedPlayers() const;
    static void printPlayers(const std::string &position, const std::vector<std::shared_ptr<Player>> &players);

    std::vector<std::shared_ptr<Player>> players;
    std::string formation;
    std::vector<std::shared_ptr<Player>> goalkeeper;
    std::vector<std::shared_ptr<Player>> defenders;
    std::vector<std::shared_ptr<Player>> midfielders;
    std::vector<std::shared_ptr<Player>> attackers;
    std::vector<std::shared_ptr<Player>> substitutes;
    constexpr int target_substitutes_number = 5;
};
