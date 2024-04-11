#include "Schedule.hpp"

#include <fstream>
#include <sstream>

int Schedule::matches_played = 0;

Schedule::Schedule(const std::vector<NationalTeam> &national_teams) : matches{loadGroupStage(national_teams)}
{
}

auto Schedule::loadGroupStage(const std::vector<NationalTeam> &national_teams) -> std::vector<Match>
{
    constexpr auto file_path = "../data/group_stage_schedule.txt";
    std::ifstream file{file_path};
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << file_path << std::endl;
        exit(1);
    }

    std::vector<Match> matches{};
    std::string line{};
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string home_team_name;
        std::string away_team_name;
        std::string date;
        if (!(iss >> home_team_name >> away_team_name >> date))
        {
            std::cerr << "Error: Invalid group schadule data format: " << line << std::endl;
            exit(1);
        }
        std::shared_ptr<NationalTeam> home_team{nullptr};
        std::shared_ptr<NationalTeam> away_team{nullptr};
        for (const auto &national_team: national_teams)
        {
            if (national_team.getCountryName() == nationality_utils::stringToNationality(home_team_name))
            {
                home_team = std::make_shared<NationalTeam>(national_team);
            }
            else if (national_team.getCountryName() == nationality_utils::stringToNationality(away_team_name))
            {
                away_team = std::make_shared<NationalTeam>(national_team);
            }
        }
        std::array opponents = {home_team, away_team};
        matches.emplace_back(date, MatchStage::GroupStage, opponents);
    }
    return matches;
}

void Schedule::show(const MatchStage match_stage) const
{
    if (match_stage == MatchStage::GroupStage)
    {
        std::cout << "Schedule for group stage" << std::endl;
    }
    {
        std::cout << "Schedule for knockout stage" << std::endl;
    }

    for (const auto &match: matches)
    {
        if (match.getStage() == match_stage)
        {
            match.showInformation();
        }
    }
}

void Schedule::playNextMatch()
{
    matches.at(matches_played).simulate();
    matches_played++;
}

void Schedule::showNextMatch() const
{
    for (const auto &match: matches)
    {
        if (!match.isFinished())
        {
            match.showInformation();
            break;
        }
    }
}

void Schedule::generateNextKnockoutStage()
{
    //TODO analize promotion teams
    if (matches_played == 36)
    {
        //TODO generate 1/8
    }
    else if (matches_played == 44)
    {
        //TODO generate 1/4
    }
    else if (matches_played == 48)
    {
        //TODO generate 1/2
    }
    else if (matches_played == 50)
    {
        //TODO generate final
    }
    //TODO handle this situation
}
