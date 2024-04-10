#pragma once

#include "player/Player.hpp"

#include <memory>
#include <vector>

class Squad
{
public:
    explicit Squad(const std::vector<std::shared_ptr<Player>> &new_players);
    void setSquad();
    void show() const;
    [[nodiscard]] auto isSquadSet() const -> bool;
    [[nodiscard]] auto getOverall() const -> int;
    [[nodiscard]] auto getAllFieldPlayers() const -> std::array<std::shared_ptr<Player>, 10>;

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
