#include "national_team/NationalTeam.hpp"

#include "national_team/statistics/GroupStatistics.hpp"
#include "national_team/statistics/KnockoutStageStatistics.hpp"

#include <fstream>
#include <sstream>


NationalTeam::NationalTeam(const Nationality new_country_name, const int new_position_in_ranking)
    : county_name{new_country_name},
      position_in_ranking{new_position_in_ranking}
{
    loadPlayers();
    squad = std::make_shared<Squad>(Squad(getSquadPlayers()));
    statistics.push_back(std::make_shared<GroupStatistics>());
}

void NationalTeam::loadPlayers()
{
    const auto file_path = "../data/players/" + nationality_utils::nationalityToString(county_name, true) + ".txt";
    std::ifstream file{file_path};
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file " << file_path << std::endl;
        exit(1);
    }

    players.clear();

    std::string line{};
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string first_name, last_name, position;
        int overall;
        if (!(iss >> first_name >> last_name >> overall >> position))
        {
            std::cerr << "Error: Invalid player data format: " << line << std::endl;
            exit(1);
        }
        Player player{first_name, last_name, overall, county_name, position_utils::stringToPosition(position)};
        players.push_back(player);
    }
}

auto NationalTeam::getSquadPlayers() const -> std::vector<std::shared_ptr<Player>>
{
    std::vector<std::shared_ptr<Player>> squad_players;
    squad_players.reserve(players.size());
    for (const auto &player: players)
    {
        squad_players.push_back(std::make_shared<Player>(player));
    }
    return squad_players;
}

auto NationalTeam::getCountryName() const -> Nationality
{
    return county_name;
}

auto NationalTeam::getPositionInRanking() const -> int
{
    return position_in_ranking;
}

auto NationalTeam::getSquad() const -> std::shared_ptr<Squad>
{
    return squad;
}

void NationalTeam::showStatistics(const MatchStage stage) const
{
    std::cout << nationality_utils::nationalityToString(county_name);
    std::cout << "Position in UEFA ranking: " << position_in_ranking << std::endl;

    if (stage == MatchStage::GroupStage)
    {
        showGroupStageStatistics();
    }
    else
    {
        showKnockoutStageStatistics();
    }
}

void NationalTeam::showGroupStageStatistics() const
{
    const auto group_statistics = std::dynamic_pointer_cast<GroupStatistics>(statistics.at(0));

    std::cout << "Statistics in group" << std::endl;
    const auto promotion_info = group_statistics->isPromoted()
                                    ? "Promoted to knockout stage: Yes"
                                    : "Promoted to knockout stage: No";
    std::cout << "Matches played: " << group_statistics->getMatchesPlayed() << std::endl;
    std::cout << "Points: " << group_statistics->getPoints() << std::endl;
    std::cout << "Wins: " << group_statistics->getWins() << std::endl;
    std::cout << "Draws: " << group_statistics->getDraws() << std::endl;
    std::cout << "Loses: " << group_statistics->getLoses() << std::endl;
    std::cout << "Goals scored: " << group_statistics->getGoalsScored() << std::endl;
    std::cout << "Goals conceded: " << group_statistics->getGoalsConceded() << std::endl;
    std::cout << "Yellow cards: " << group_statistics->getYellowCards() << std::endl;
    std::cout << "Red cards: " << group_statistics->getRedCards() << std::endl;
    std::cout << "Got promoted: " << promotion_info << std::endl;
}

void NationalTeam::showKnockoutStageStatistics() const
{
    const auto knockout_statistics = std::dynamic_pointer_cast<KnockoutStageStatistics>(statistics.at(1));

    std::cout << "Statistics in knockoutstage" << std::endl;
    std::cout << "Actual stage: " << knockout_statistics->getStage() << std::endl;
    std::cout << "Wins: " << knockout_statistics->getWins() << std::endl;
    std::cout << "Draws: " << knockout_statistics->getDraws() << std::endl;
    std::cout << "Loses: " << knockout_statistics->getLoses() << std::endl;
    std::cout << "Goals scored: " << knockout_statistics->getGoalsScored() << std::endl;
    std::cout << "Goals conceded: " << knockout_statistics->getGoalsConceded() << std::endl;
    std::cout << "Yellow cards: " << knockout_statistics->getYellowCards() << std::endl;
    std::cout << "Red cards: " << knockout_statistics->getRedCards() << std::endl;
}

auto NationalTeam::getGroupStageStatistics() const -> std::shared_ptr<GroupStatistics>
{
    auto ptr = std::dynamic_pointer_cast<GroupStatistics>(statistics.at(0));
    if (ptr)
    {
        return ptr;
    }
}

auto NationalTeam::getKnockoutStageStatistics() const -> std::shared_ptr<KnockoutStageStatistics>
{
    auto ptr = std::dynamic_pointer_cast<KnockoutStageStatistics>(statistics.at(0));
    if (ptr)
    {
        return ptr;
    }
    std::cerr << "Error: Knockout stage didn't stared." << std::endl;
    exit(1);
}
