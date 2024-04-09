#include "squad/Squad.hpp"

#include "squad/FormationsManager.hpp"

#include <iostream>
#include <algorithm>

Squad::Squad(const std::vector<std::shared_ptr<Player>> &new_players) : players{new_players}
{
}

void Squad::setSquad()
{
    chooseFormation();
    choosePlayersByPosition(Position::Goalkeeper, goalkeeper);
    choosePlayersByPosition(Position::Defender, defenders);
    choosePlayersByPosition(Position::Midfielder, midfielders);
    choosePlayersByPosition(Position::Attacker, attackers);
    chooseSubstitutes();
}

void Squad::chooseFormation()
{
    const auto formation_manager = FormationsManager::instance();
    auto valid_input = false;

    std::cout << "List of formations:\n";
    const auto formation_number = formation_manager->showAll();
    do
    {
        char selected_formation;
        std::cout << "Select formation: ";
        std::cin >> selected_formation;

        if (std::isdigit(selected_formation))
        {
            const auto formation_index = selected_formation - '0';
            if (formation_index >= 1 && formation_index <= formation_number)
            {
                valid_input = true;
                formation = formation_manager->getFormation(selected_formation - 1);
            }
            else
            {
                std::cout << "Invalid formation index. Please enter a valid number." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
    } while (!valid_input);
}

void Squad::choosePlayersByPosition(const Position position,
                                    std::vector<std::shared_ptr<Player>> &players_by_position)
{
    const auto target_players_number = getTargetNumberOfPlayersByPosition(position);
    auto selected_players_number = 0;
    const auto selected_position = position_utils::positionToString(position);

    std::cout << "List of " << selected_position << "s\n"; //
    printAllPlayersByPosition(position);
    do
    {
        std::string player_name;
        std::cout << "Select the" << selected_players_number + 1 << '/' << target_players_number << ' ' <<
                selected_position << " (enter full name): ";
        std::cin >> player_name;

        auto it = std::ranges::find_if(players.begin(), players.end(),
                                       [&player_name](const std::shared_ptr<Player> &player)
                                       {
                                           return player->getName() == player_name;
                                       });
        if (it != players.end())
        {
            players_by_position.push_back(*it);
            players.erase(it);
            selected_players_number++;
        }
        else if (it->get()->getInjury().isInjured() == true)
        {
            std::cout << "Player " << player_name << " is injured. Please enter valid player name." << std::endl;
        }
        else
        {
            std::cout << "Player " << player_name <<
                    " doesn't exists. Please enter player name that exist's on the list." << std::endl;
        }
    } while (selected_players_number != target_players_number);
}

void Squad::printAllPlayersByPosition(const Position position) const
{
    auto counter = 0;
    for (const auto &player: players)
    {
        if (player->getPosition() == position && player->getInjury().isInjured() == false)
        {
            std::cout << ++counter << ". " << player->getName() << "(" << player->getOverall() << ")\n";
        }
    }
}

void Squad::chooseSubstitutes()
{
    auto selected_substitutes_number = 0;

    std::cout << "List of substitutes\n";
    printAllUnselectedPlayers();
    do
    {
        std::string player_name;
        std::cout << "Select the" << selected_substitutes_number + 1 << '/' << target_substitutes_number <<
                " attacker (enter full name): ";
        std::cin >> player_name;

        auto it = std::ranges::find_if(players.begin(), players.end(),
                                       [&player_name](const std::shared_ptr<Player> &player)
                                       {
                                           return player->getName() == player_name;
                                       });
        if (it != players.end())
        {
            substitutes.push_back(*it);
            players.erase(it);
            selected_substitutes_number++;
        }
        else if (it->get()->getInjury().isInjured() == true)
        {
            std::cout << "Player " << player_name << " is injured. Please enter valid player name." << std::endl;
        }
        else
        {
            std::cout << "Player " << player_name <<
                    " doesn't exists. Please enter player name that exist's on the list." << std::endl;
        }
    } while (selected_substitutes_number != target_substitutes_number);
}

void Squad::printAllUnselectedPlayers() const
{
    auto counter = 0;
    for (const auto &player: players)
    {
        if (player->getInjury().isInjured() == false)
        {
            std::cout << ++counter << ". " << player->getName() << "(" << player->getOverall() << ")\n";
        }
    }
}

void Squad::show() const
{
    std::cout << "Formation: " << formation << std::endl;
    printPlayers("Goalkeeper", goalkeeper);
    printPlayers("Defenders", defenders);
    printPlayers("Midfielders", midfielders);
    printPlayers("Attackers", attackers);
}

void Squad::printPlayers(const std::string &position, const std::vector<std::shared_ptr<Player>> &players)
{
    std::cout << position << ": ";
    for (const auto &player: players)
    {
        std::cout << player->getName() << ", ";
    }
    std::cout << std::endl;
}

auto Squad::isSquadSet() const -> bool
{
    if (getTargetNumberOfPlayersByPosition(Position::Goalkeeper) != goalkeeper.size())
    {
        return false;
    }
    if (getTargetNumberOfPlayersByPosition(Position::Defender) != defenders.size())
    {
        return false;
    }
    if (getTargetNumberOfPlayersByPosition(Position::Midfielder) != midfielders.size())
    {
        return false;
    }
    if (getTargetNumberOfPlayersByPosition(Position::Attacker) != attackers.size())
    {
        return false;
    }
    if (target_substitutes_number != substitutes.size())
    {
        return false;
    }
    return true;
}

auto Squad::getTargetNumberOfPlayersByPosition(const Position position) const -> int
{
    switch (position)
    {
        case Position::Goalkeeper:
            return 1;
        case Position::Defender:
            return std::stoi(formation.substr(0, 1));
        case Position::Midfielder:
            return std::stoi(formation.substr(2, 1));
        case Position::Attacker:
            return std::stoi(formation.substr(4, 1));
        default:
            return 0;
    }
}

auto Squad::getOverall() const -> int
{
    auto overall = 0;
    overall += sumOveral(goalkeeper);
    overall += sumOveral(defenders);
    overall += sumOveral(midfielders);
    overall += sumOveral(attackers);
    return overall;
}

auto Squad::sumOveral(std::vector<std::shared_ptr<Player>> players) const -> int
{
    auto overall = 0;
    for (const auto &player: goalkeeper)
    {
        overall += player->getOverall();
    }
    return overall;
}
