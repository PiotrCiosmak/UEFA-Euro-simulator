#include "Euro.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

Euro::Euro() : name{"EURO 2024"}, national_teams{loadNationalTeams()}, schedule{national_teams}, groups{loadGroups()},
               start_date{"June-14-2024"}, winner{nullptr}
{
}

auto Euro::getNationalTeam(const Nationality country_name) const -> std::shared_ptr<NationalTeam>
{
    for (const auto &national_team: national_teams)
    {
        if (nationality_utils::nationalityToString(national_team.getCountryName()) ==
            nationality_utils::nationalityToString(country_name))
        {
            return std::make_shared<NationalTeam>(national_team);
        }
    }
    std::cerr << "Error: This national teams isn't in database" << std::endl;
    exit(1);
}

auto Euro::getGroup(const std::string &group_name) const -> std::shared_ptr<Group>
{
    for (const auto &group: groups)
    {
        if (group.getName() == group_name)
        {
            return std::make_shared<Group>(group);
        }
    }
    std::cerr << "Error: Unable to find group name " << group_name << std::endl;
    exit(1);
}

void Euro::showName() const
{
    std::cout << name << std::endl;
}

void Euro::showStartDate() const
{
    std::cout << "Start on " << start_date << '.' << std::endl;
}

auto Euro::getSchedule() const -> Schedule
{
    return schedule;
}

void Euro::start()
{
    while (true)
    {
        showMenu();
        std::string selected_option;
        std::getline(std::cin, selected_option);

        switch (selected_option.at(0))
        {
            case '0':
                close();
            case '1':
                schedule.playNextMatch();
                break;
            case '2':
                schedule.showNextMatch();
                break;
            case '3':
                schedule.show(MatchStage::GroupStage);
                break;
            case '4':
                schedule.show(MatchStage::KnockoutStage); //TODO load knockoutstage
                break;
            case '5':
                for (const auto &group: groups)
                {
                    group.showTable();
                }
                break;
            case '6':
                //TODO print detail stastistics about match, squad, stats etc.
                break;
            case '7':
                //TODO print player table of goals, assist, yellow/red cards, clean sheet
                break;
            case '8':
                showWinner();
                break;
            default:
                invalidOption();
        }
    }
}

void Euro::showMenu()
{
    std::cout << "\nMENU" << std::endl;
    std::cout << "1. Simulate next match" << std::endl;
    std::cout << "2. Show next match" << std::endl;
    std::cout << "3. Show group stage schedule" << std::endl;
    std::cout << "4. Show knockout stage schedule" << std::endl;
    std::cout << "5. Show group information" << std::endl;
    std::cout << "6. Show finished matches" << std::endl;
    std::cout << "7. Show players statistisc" << std::endl;
    std::cout << "8. Show winner" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Select option: ";
}

void Euro::invalidOption()
{
    std::cout << "Invalid option selected. Please enter a valid number." << std::endl;
}

void Euro::showAllMembers() const
{
    std::cout << "List od all members:" << std::endl;;
    for (const auto &national_team: national_teams)
    {
        std::cout << "- " << nationality_utils::nationalityToString(national_team.getCountryName()) << std::endl;
    }
}

void Euro::showWinner() const
{
    if (winner)
    {
        std::cout << "The winner of " << name << " is " << nationality_utils::nationalityToString(
                    winner->getCountryName()) << '.' <<
                std::endl;
    }
    else
    {
        std::cout << "The tournament is still ongoin. There is no winner yet." << std::endl;
    }
}

auto Euro::loadNationalTeams() -> std::vector<NationalTeam>
{
    constexpr auto file_path = "../data/national_teams.txt";
    std::ifstream file{file_path};
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << file_path << std::endl;
        exit(1);
    }

    std::vector<NationalTeam> national_teams{};
    std::string line{};
    while (std::getline(file, line))
    {
        std::istringstream iss{line};
        std::string country_name;
        int position_in_ranking;
        if (!(iss >> country_name >> position_in_ranking))
        {
            std::cerr << "Error: Invalid national team data format: " << line << std::endl;
            exit(1);
        }
        national_teams.emplace_back(nationality_utils::stringToNationality(country_name), position_in_ranking);
    }
    return national_teams;
}

auto Euro::loadGroups() -> std::vector<Group>
{
    constexpr auto file_path = "../data/groups.txt";
    std::ifstream file{file_path};
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << file_path << std::endl;
        exit(1);
    }

    std::vector<Group> groups{};
    std::string line{};
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string group_name;
        std::array<std::string, 4> national_teams_names;
        if (!(iss >> group_name >> national_teams_names.at(0) >> national_teams_names.at(1) >> national_teams_names.
              at(2) >> national_teams_names.at(3)))
        {
            std::cerr << "Error: Invalid group data format: " << line << std::endl;
            exit(1);
        }
        group_name = "GROUP " + group_name;

        std::array<std::shared_ptr<NationalTeam>, 4> national_teams_in_group{};
        auto counter = 0;
        for (const auto &national_team: national_teams)
        {
            for (const auto &national_team_name: national_teams_names)
            {
                if (national_team.getCountryName() == nationality_utils::stringToNationality(national_team_name))
                {
                    national_teams_in_group.at(counter) = std::make_shared<NationalTeam>(national_team);
                    counter++;
                }
            }
        }

        Group group{group_name, national_teams_in_group};
        groups.push_back(group);
    }
    return groups;
}

void Euro::close()
{
    std::cout << "Closing application..." << std::endl;
    exit(0);
}
