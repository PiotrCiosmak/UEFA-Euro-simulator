#include "match/Match.hpp"

#include <cstdlib>

Match::Match(std::string new_date, const MatchStage new_stage,
             const std::pair<std::shared_ptr<NationalTeam>, std::shared_ptr<NationalTeam>> &new_national_team) : date{
        std::move(new_date)
    }, stage{new_stage}, national_team{new_national_team},
    squad{Squad{*national_team.first->getSquad()}, Squad{*national_team.second->getSquad()}},
    statistics{MatchStatistics{}}, overall_addition{calculateOverallAddition()}, finished{false}
{
}

auto Match::calculateOverallAddition() const -> std::pair<int, int>
{
    const std::pair overall{squad.first.getOverall(), squad.second.getOverall()};
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
    std::cout << nationality_utils::nationalityToString(national_team.first->getCountryName()) << std::endl;
    squad.first.setSquad();
    std::cout << std::endl << nationality_utils::nationalityToString(national_team.first->getCountryName()) <<
            std::endl;
    squad.second.setSquad();

    showStage();
    startSimulation(90);
    if (const auto goals = statistics.getGoals(); stage == MatchStage::KnockoutStage && goals.at(0) == goals.at(1))
    {
        startSimulation(30);
        if (const auto goals = statistics.getGoals(); goals.at(0) == goals.at(1))
        {
            startPenaltySimulation();
        }
    }
    //TODO statsyki zostaja przypisane dla grupy jesli stage==group stage

    //TODO jeśli któraś drużyna zachowała czyste konto to przypisać clean_sheet +1 dla wszystkich z zespołu
    finished = true;
    showResult();
    //TODO zapytaj czy chce zobaczyć szczegółowe staty
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
        const auto detail_stage = national_team.first->getKnockoutStageStatistics()->getStage();
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
        //TODO wylosować strzelca i zapisać mu to
    }
    else if (random_number > away_probability)
    {
        statistics.awayScoreGoal();
        //TODO wylosować strzelca i zapisać mu to
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
        //TODO wylosować kto dostaje i zapisać mu to
    }
    else if (random_number > away_probability)
    {
        statistics.awayGetYellowCard();
        //TODO wylosować kto dostaje i zapisać mu to
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
        //TODO wylosować kto dostaje i zapisać mu to
        overall_addition.first += 1;
    }
    else if (random_number > away_probability)
    {
        statistics.awayGetRedCard();
        //TODO wylosować kto dostaje i zapisać mu to
        overall_addition.second -= 1;
    }
}

void Match::simulateInjury()
{
    const auto random_number = rand() % 100;
    const auto home_probability = 1 + overall_addition.first;
    const auto away_probability = 98 - overall_addition.second;
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

void Match::startPenaltySimulation()
{
    //TODO implement
    //TODO dodać wynik karnych do match statistics
}

void Match::showResult() const
{
    const auto goals = statistics.getGoals();
    std::cout << nationality_utils::nationalityToString(national_team.first->getCountryName()) << " " << goals.at(0) <<
            " : " << goals.at(1) << " " << nationality_utils::nationalityToString(
                national_team.second->getCountryName()) << std::endl;
}

void Match::showSquads() const
{
    std::cout << nationality_utils::nationalityToString(national_team.first->getCountryName()) << std::endl;
    squad.first.show();

    std::cout << std::endl << nationality_utils::nationalityToString(national_team.first->getCountryName()) <<
            std::endl;
    squad.second.show();
}

void Match::showStatistics() const
{
    statistics.show();
}
