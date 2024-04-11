#include "match/Match.hpp"

#include <cstdlib>
#include <random>

Match::Match(std::string new_date, const MatchStage new_stage,
             const std::array<std::shared_ptr<NationalTeam>, 2> &new_national_team) : date{
        std::move(new_date)
    }, stage{new_stage}, national_teams{new_national_team},
    squads{Squad{*national_teams.at(0)->getSquad()}, Squad{*national_teams.at(1)->getSquad()}},
    statistics{MatchStatistics{}}, overall_addition{calculateOverallAddition()}, finished{false}
{
    std::srand(time(nullptr));
}

auto Match::calculateOverallAddition() const -> std::pair<int, int>
{
    const std::pair overall{squads.at(0).getOverall(), squads.at(1).getOverall()};
    std::pair addition{0, 0};
    if (overall.first < 825)
    {
        addition.first += 1;
    }
    if (overall.second < 825)
    {
        addition.second -= 1;
    }
    if (overall.first > 925)
    {
        addition.first -= 1;
    }
    if (overall.second > 925)
    {
        addition.second += 1;
    }
    return addition;
}

void Match::simulate()
{
    if (finished)
    {
        std::cerr << "Error: This match has been finished!" << std::endl;
        exit(1);
    }
    for (int i = 0; i < 2; ++i)
    {
        std::cout << nationality_utils::nationalityToString(national_teams.at(i)->getCountryName()) << std::endl;
        squads.at(i).setSquad();
    }
    showStage();
    if (stage == MatchStage::GroupStage)
    {
        for (const auto &national_team: national_teams)
        {
            national_team->getGroupStageStatistics()->addMatche();
        }
    }
    else
    {
        for (const auto &national_team: national_teams)
        {
            national_team->getKnockoutStageStatistics()->addMatche();
        }
    }
    startSimulation(90);

    if (stage == MatchStage::GroupStage)
    {
        assignPoints();
    }
    else
    {
        if (const auto goals = statistics.getGoals(); stage == MatchStage::KnockoutStage && goals.at(0) == goals.at(1))
        {
            startSimulation(30);
            auto penality_result{0, 0};
            if (const auto goals = statistics.getGoals(); goals.at(0) == goals.at(1))
            {
                penality_result = getPenalityResult();
            }
            assignNextStageToWinner(penality_result);
        }
    }

    saveCleanSheets();
    finished = true;
    showResult();
    char answer;
    std::cout << "Display match details? (y/n): ";
    std::cin >> answer;
    auto valid_input = false;

    do
    {
        if (std::tolower(answer) == 'y')
        {
            valid_input = true;
            showStatistics();
        }
        else if (std::tolower(answer) == 'n')
        {
            valid_input = true;
        }
        else
        {
            std::cout << "Invalid answer. Please enter letter y or n." << std::endl;
        }
    } while (!valid_input);
}

void Match::showStage() const
{
    if (stage == MatchStage::GroupStage)
    {
        std::cout << "Group stage match!" << std::endl;
    }
    else
    {
        std::string communicate = "Knockout stage match: ";
        const auto detail_stage = national_teams.at(0)->getKnockoutStageStatistics()->getStage();
        communicate += detail_stage;
        std::cout << communicate << std::endl;
    }
}

void Match::startSimulation(int minutes)
{
    for (int i = 1; i <= minutes; ++i)
    {
        simulateGoal();
        simulateYellowCard();
        simulateRedCard();
        simulateInjury();
        if (minutes > 60)
        {
            simulateSubstitution();
        }
        if (minutes == 90)
        {
            constexpr auto max_extra_time = 6;
            minutes += rand() % max_extra_time;
        }
    }
}

void Match::simulateGoal()
{
    const auto random_number = rand() % 100;
    const auto home_probability = 2 + overall_addition.first;
    const auto away_probability = 97 - overall_addition.second;

    if (random_number < home_probability)
    {
        statistics.homeScoreGoal();
        if (stage == MatchStage::GroupStage)
        {
            national_teams.at(0)->getGroupStageStatistics()->addGoalScored();
        }
        else
        {
            national_teams.at(0)->getKnockoutStageStatistics()->addGoalScored();
        }
        const auto goal_scorer = selectGoalScorer(0);
        selectWhoAssisted(0, goal_scorer);
    }
    else if (random_number > away_probability)
    {
        statistics.awayScoreGoal();
        if (stage == MatchStage::KnockoutStage)
        {
            national_teams.at(1)->getGroupStageStatistics()->addGoalScored();
        }
        else
        {
            national_teams.at(1)->getKnockoutStageStatistics()->addGoalScored();
        }
        const auto goal_scorer = selectGoalScorer(1);
        selectWhoAssisted(1, goal_scorer);
    }
}

auto Match::selectGoalScorer(const int team_index) const -> std::shared_ptr<Player>
{
    const auto players = squads.at(team_index).getAllFieldPlayers();
    const auto random_number = rand() % 100;
    if (random_number < 30)
    {
        std::vector<std::shared_ptr<Player>> atackers;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Attacker)
            {
                atackers.push_back(player);
            }
        }
        const auto atacker_index = rand() % atackers.size();
        auto atacker = atackers.at(atacker_index);
        atacker->getStatistics().assists += 1;
        return atacker;
    }
    if (random_number < 90)
    {
        std::vector<std::shared_ptr<Player>> midfielders;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Midfielder)
            {
                midfielders.push_back(player);
            }
        }
        const auto midfielder_index = rand() % midfielders.size();
        auto midfielder = midfielders.at(midfielder_index);
        midfielder->getStatistics().assists += 1;
        return midfielder;
    }
    std::vector<std::shared_ptr<Player>> defenders;
    for (const auto &player: players)
    {
        if (player->getPosition() == Position::Defender)
        {
            defenders.push_back(player);
        }
    }
    const auto defender_index = rand() % defenders.size();
    auto defender = defenders.at(defender_index);
    defender->getStatistics().assists += 1;
    return defender;
}

void Match::selectWhoAssisted(const int team_index, const std::shared_ptr<Player> &goal_scorer) const
{
    const auto players = squads.at(team_index).getAllFieldPlayers();
    std::array<std::shared_ptr<Player>, 9> filtered_players{};
    for (int i = 0; i < players.size(); ++i)
    {
        const auto candidate = players.at(i);
        if (candidate != goal_scorer)
        {
            filtered_players.at(i) = candidate;
        }
    }

    const auto random_number = rand() % 100;
    if (random_number < 70)
    {
        std::vector<std::shared_ptr<Player>> atackers;
        for (const auto &player: filtered_players)
        {
            if (player->getPosition() == Position::Attacker)
            {
                atackers.push_back(player);
            }
        }
        const auto atacker_index = rand() % atackers.size();
        atackers.at(atacker_index)->getStatistics().goals += 1;
    }
    else if (random_number >= 70 && random_number < 90)
    {
        std::vector<std::shared_ptr<Player>> midfielders;
        for (const auto &player: filtered_players)
        {
            if (player->getPosition() == Position::Midfielder)
            {
                midfielders.push_back(player);
            }
        }
        const auto midfielder_index = rand() % midfielders.size();
        midfielders.at(midfielder_index)->getStatistics().goals += 1;
    }
    else
    {
        std::vector<std::shared_ptr<Player>> defenders;
        for (const auto &player: filtered_players)
        {
            if (player->getPosition() == Position::Defender)
            {
                defenders.push_back(player);
            }
        }
        const auto defender_index = rand() % defenders.size();
        defenders.at(defender_index)->getStatistics().goals += 1;
    }
}

void Match::simulateYellowCard()
{
    const auto random_number = rand() % 100;
    const auto home_probability = 5 + overall_addition.first;
    const auto away_probability = 94 - overall_addition.second;
    if (random_number < home_probability)
    {
        statistics.homeGetYellowCard();
        if (stage == MatchStage::GroupStage)
        {
            national_teams.at(0)->getGroupStageStatistics()->addYellowCard();
        }
        else
        {
            national_teams.at(0)->getKnockoutStageStatistics()->addYellowCard();
        }
        selectWhoGetsYellowCard(0);
    }
    else if (random_number > away_probability)
    {
        statistics.awayGetYellowCard();
        if (stage == MatchStage::KnockoutStage)
        {
            national_teams.at(1)->getGroupStageStatistics()->addYellowCard();
        }
        else
        {
            national_teams.at(1)->getKnockoutStageStatistics()->addYellowCard();
        }
        selectWhoGetsYellowCard(1);
    }
}

void Match::selectWhoGetsYellowCard(const int team_index) const
{
    const auto players = squads.at(team_index).getAllFieldPlayers();
    const auto random_number = rand() % 100;
    if (random_number < 5)
    {
        std::vector<std::shared_ptr<Player>> atackers;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Attacker)
            {
                atackers.push_back(player);
            }
        }
        const auto atacker_index = rand() % atackers.size();
        atackers.at(atacker_index)->getStatistics().yellow_cards += 1;
    }
    else if (random_number >= 5 && random_number < 20)
    {
        std::vector<std::shared_ptr<Player>> midfielders;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Midfielder)
            {
                midfielders.push_back(player);
            }
        }
        const auto midfielder_index = rand() % midfielders.size();
        midfielders.at(midfielder_index)->getStatistics().yellow_cards += 1;
    }
    else
    {
        std::vector<std::shared_ptr<Player>> defenders;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Defender)
            {
                defenders.push_back(player);
            }
        }
        const auto defender_index = rand() % defenders.size();
        defenders.at(defender_index)->getStatistics().yellow_cards += 1;
    }
}

void Match::simulateRedCard()
{
    const auto random_number = rand() % 100;
    const auto home_probability = 1 + overall_addition.first;
    const auto away_probability = 98 - overall_addition.second;
    if (random_number < home_probability)
    {
        statistics.homeGetRedCard();
        overall_addition.first += 1;
        if (stage == MatchStage::GroupStage)
        {
            national_teams.at(0)->getGroupStageStatistics()->addRedCard();
        }
        else
        {
            national_teams.at(0)->getKnockoutStageStatistics()->addRedCard();
        }
        selectWhoGetsRedCard(0);
    }
    else if (random_number > away_probability)
    {
        statistics.awayGetRedCard();
        overall_addition.second -= 1;
        if (stage == MatchStage::KnockoutStage)
        {
            national_teams.at(1)->getGroupStageStatistics()->addRedCard();
        }
        else
        {
            national_teams.at(1)->getKnockoutStageStatistics()->addRedCard();
        }
        selectWhoGetsRedCard(1);
    }
}

void Match::selectWhoGetsRedCard(int team_index) const
{
    const auto players = squads.at(team_index).getAllFieldPlayers();
    const auto random_number = rand() % 100;
    if (random_number < 3)
    {
        std::vector<std::shared_ptr<Player>> atackers;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Attacker)
            {
                atackers.push_back(player);
            }
        }
        const auto atacker_index = rand() % atackers.size();
        atackers.at(atacker_index)->getStatistics().red_cards += 1;
    }
    else if (random_number >= 3 && random_number < 10)
    {
        std::vector<std::shared_ptr<Player>> midfielders;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Midfielder)
            {
                midfielders.push_back(player);
            }
        }
        const auto midfielder_index = rand() % midfielders.size();
        midfielders.at(midfielder_index)->getStatistics().red_cards += 1;
    }
    else
    {
        std::vector<std::shared_ptr<Player>> defenders;
        for (const auto &player: players)
        {
            if (player->getPosition() == Position::Defender)
            {
                defenders.push_back(player);
            }
        }
        const auto defender_index = rand() % defenders.size();
        defenders.at(defender_index)->getStatistics().red_cards += 1;
    }
}

void Match::simulateInjury()
{
    const auto random_number = rand() % 100;
    const auto home_probability = 1 + overall_addition.first;
    const auto away_probability = 98 - overall_addition.second;
    auto getRandomNumber = []()
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<> dis(0, 1);

        const auto random_number = dis(gen);

        if (random_number < 0.6)
        {
            return 1 + static_cast<int>(random_number * 10);
        }
        if (random_number < 0.9)
        {
            return 11 + static_cast<int>((random_number - 0.6) * 20);
        }
        return 31 + static_cast<int>((random_number - 0.9) * 70);
    };

    if (random_number < home_probability)
    {
        if (statistics.getAvailableChanges().at(0) > 0)
        {
            statistics.homeMakeChange();
        }
        else
        {
            overall_addition.first += 1;
        }
        const auto players = squads.at(0).getAllFieldPlayers();

        const auto player_index = rand() % players.size();
        players.at(player_index)->getInjury().setDaysToRecovery(getRandomNumber());
    }
    else if (random_number > away_probability)
    {
        if (statistics.getAvailableChanges().at(1) > 0)
        {
            statistics.awayMakeChange();
        }
        else
        {
            overall_addition.second -= 1;
        }
        const auto players = squads.at(1).getAllFieldPlayers();

        const auto player_index = rand() % players.size();
        players.at(player_index)->getInjury().setDaysToRecovery(getRandomNumber());
    }
}

void Match::simulateSubstitution()
{
    const auto random_number = rand() % 100;
    constexpr auto home_probability = 10;
    constexpr auto away_probability = 88;
    if (random_number < home_probability)
    {
        if (statistics.getAvailableChanges().at(0) > 0)
        {
            statistics.homeMakeChange();
        }
    }
    else if (random_number > away_probability)
    {
        if (statistics.getAvailableChanges().at(1) > 0)
        {
            statistics.awayMakeChange();
        }
    }
}

auto Match::getPenalityResult() -> std::array<int, 2>
{
    const auto home_scored = rand() % 10 + 3;
    const auto random_factor = std::rand() % 2 == 0 ? -1 : 1;
    const auto away_scored = home_scored + random_factor;
    return {home_scored, away_scored};
}

void Match::saveCleanSheets() const
{
    if (statistics.getGoals().at(0) == 0)
    {
        const auto players = squads.at(1).getAllPlayers();
        for (const auto &player: players)
        {
            player->getStatistics().clean_sheets += 1;
        }
    }
    else if (statistics.getGoals().at(1) == 0)
    {
        const auto players = squads.at(0).getAllPlayers();
        for (const auto &player: players)
        {
            player->getStatistics().clean_sheets += 1;
        }
    }
}

void Match::assignPoints() const
{
    const auto home_goals = statistics.getGoals().at(0);
    const auto away_goals = statistics.getGoals().at(1);
    if (home_goals > away_goals)
    {
        national_teams.at(0)->getGroupStageStatistics()->addPoints(3);
    }
    else if (home_goals == away_goals)
    {
        for (const auto &national_team: national_teams)
        {
            national_team->getGroupStageStatistics()->addPoints(1);
        }
    }
    else
    {
        national_teams.at(1)->getGroupStageStatistics()->addPoints(3);
    }
}

void Match::assignNextStageToWinner(std::array<int, 2> penalty_result) const
{
    const auto home_goals = statistics.getGoals().at(0);
    const auto away_goals = statistics.getGoals().at(1);
    std::shared_ptr<NationalTeam> winner = {nullptr};
    if (home_goals > away_goals)
    {
        winner = national_teams.at(0);
    }
    else if (away_goals > home_goals)
    {
        winner = national_teams.at(1);
    }
    else
    {
        if (penalty_result.at(0) > penalty_result.at(1))
        {
            winner = national_teams.at(0);
        }
        else
        {
            winner = national_teams.at(1);
        }
    }
    winner->getKnockoutStageStatistics()->setNextStage();
}

void Match::showResult() const
{
    const auto goals = statistics.getGoals();
    std::cout << nationality_utils::nationalityToString(national_teams.at(0)->getCountryName()) << " " << goals.at(0) <<
            " : " << goals.at(1) << " " << nationality_utils::nationalityToString(
                national_teams.at(1)->getCountryName()) << std::endl;
}

void Match::showSquads() const
{
    for (int i = 0; i < 2; ++i)
    {
        std::cout << nationality_utils::nationalityToString(national_teams.at(i)->getCountryName()) << std::endl;
        squads.at(i).show();
    }
}

void Match::showStatistics() const
{
    statistics.show();
}

void Match::showInformation() const
{
    if (stage == MatchStage::GroupStage)
    {
        std::cout << "Grop stage: ";
    }
    else
    {
        std::cout << "Knockout stage: ";
    }
    std::cout << nationality_utils::nationalityToString(national_teams.at(0)->getCountryName()) << " vs " <<
            nationality_utils::nationalityToString(national_teams.at(1)->getCountryName()) << ", " << date << std::endl;
}

auto Match::getStage() const -> MatchStage
{
    return stage;
}

auto Match::isFinished() const -> bool
{
    return finished;
}
