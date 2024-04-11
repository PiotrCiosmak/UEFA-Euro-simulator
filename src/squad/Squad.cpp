#include "squad/Squad.hpp"

#include "squad/FormationsManager.hpp"

#include <iostream>
#include <algorithm>
#include <sstream>

Squad::Squad(const std::vector<std::shared_ptr<Player>> &new_players) : players{new_players}
{
}

void Squad::setSquad()
{
    /*
    DLA TESTÓW PODCZAS PRZEZENTACJI PROJEKTU
    formation = "4-5-1";
    goalkeeper.push_back(players.at(0));
    defenders.push_back(players.at(4));
    defenders.push_back(players.at(5));
    defenders.push_back(players.at(6));
    defenders.push_back(players.at(7));
    midfielders.push_back(players.at(15));
    midfielders.push_back(players.at(16));
    midfielders.push_back(players.at(17));
    midfielders.push_back(players.at(18));
    midfielders.push_back(players.at(19));
    attackers.push_back(players.at(22));
    substitutes.push_back(players.at(8));
    substitutes.push_back(players.at(9));
    substitutes.push_back(players.at(10));
    substitutes.push_back(players.at(11));
    substitutes.push_back(players.at(12));*/
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
        std::string selected_formation;
        std::cout << "Select formation: ";
        std::getline(std::cin, selected_formation);
        const auto selected_formation_index = stoi(selected_formation) - 1;
        if (selected_formation_index >= 0 && selected_formation_index < formation_number)
        {
            valid_input = true;
            formation = formation_manager->getFormation(selected_formation_index);
        }
        else
        {
            std::cout << "Invalid formation index. Please enter a valid number." << std::endl;
        }
    } while (!valid_input);
}

void Squad::choosePlayersByPosition(const Position position,
                                    std::vector<std::shared_ptr<Player>> &players_by_position)
{
    const auto target_players_number = getTargetNumberOfPlayersByPosition(position);
    auto selected_players_number = 0;
    const auto selected_position = position_utils::positionToString(position);

    std::cout << "List of " << selected_position << "s\n";
    printAllPlayersByPosition(position);
    do
    {
        std::string player_name;
        std::cout << "Select the " << selected_players_number + 1 << '/' << target_players_number << ' ' <<
                selected_position << " (enter full name): ";
        std::getline(std::cin, player_name);

        auto it = std::ranges::find_if(players.begin(), players.end(),
                                       [&player_name](const std::shared_ptr<Player> &player)
                                       {
                                           return player->getName() == player_name;
                                       });
        if (it->get() == nullptr)
        {
            std::cerr << "Invalid choice. Try again." << std::endl;
            continue;
        }
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
        std::cout << "Select the " << selected_substitutes_number + 1 << '/' << target_substitutes_number <<
                " substitutes (enter full name): ";
        std::getline(std::cin, player_name);

        auto it = std::ranges::find_if(players.begin(), players.end(),
                                       [&player_name](const std::shared_ptr<Player> &player)
                                       {
                                           return player->getName() == player_name;
                                       });
        if (it->get() == nullptr)
        {
            std::cerr << "Invalid choice. Try again." << std::endl;
            continue;
        }
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
    std::vector<int> numbers_from_formation;
    std::istringstream ss{formation};
    std::string number_of_players_on_position;

    while (std::getline(ss, number_of_players_on_position, '-'))
    {
        size_t pos = number_of_players_on_position.find('(');
        if (pos != std::string::npos)
        {
            number_of_players_on_position = number_of_players_on_position.substr(0, pos);
        }
        numbers_from_formation.push_back(std::stoi(number_of_players_on_position));
    }

    const auto size_of_numbers_from_formation = numbers_from_formation.size();


    switch (position)
    {
        case Position::Goalkeeper:
            return 1;
        case Position::Defender:
            return numbers_from_formation.at(0);
        case Position::Midfielder:
            if (size_of_numbers_from_formation == 3)
            {
                return numbers_from_formation.at(1);
            }
            if (size_of_numbers_from_formation == 4)
            {
                return numbers_from_formation.at(1) + numbers_from_formation.at(2);
            }
            return numbers_from_formation.at(1) + numbers_from_formation.at(2) + numbers_from_formation.at(3);
        case Position::Attacker:
            if (numbers_from_formation.size() == 3)
            {
                return numbers_from_formation.at(2);
            }
            if (size_of_numbers_from_formation == 4)
            {
                return numbers_from_formation.at(3);
            }
            return numbers_from_formation.at(4);
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

auto Squad::getAllFieldPlayers() const -> std::array<std::shared_ptr<Player>, 10>
{
    std::array<std::shared_ptr<Player>, 10> players = {};
    auto counter = 0;
    for (const auto &player: defenders)
    {
        players.at(counter) = player;
        counter++;
    }
    for (const auto &player: midfielders)
    {
        players.at(counter) = player;
        counter++;
    }
    for (const auto &player: attackers)
    {
        players.at(counter) = player;
        counter++;
    }
    return players;
}

auto Squad::getAllPlayers() const -> std::array<std::shared_ptr<Player>, 11>
{
    const auto field_players = getAllFieldPlayers();
    std::array<std::shared_ptr<Player>, 11> players = {};
    auto counter = 0;
    for (const auto &player: field_players)
    {
        players.at(counter) = player;
        counter++;
    }
    players.at(counter) = goalkeeper.at(0);
    return players;
}
