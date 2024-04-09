#pragma once

#include "MatchStatistics.hpp"
#include "national_team/NationalTeam.hpp"

#include <memory>
#include <string>

class Match
{
public:
    Match(std::string new_date, MatchStage new_stage,
          const std::pair<std::shared_ptr<NationalTeam>, std::shared_ptr<NationalTeam>> &new_national_team);
    void simulate();
    void showResult() const;
    void showSquads() const;
    void showStatistics() const;

private:
    [[nodiscard]] auto calculateOverallAddition() const -> std::pair<int, int>;
    void showStage() const;
    void startSimulation(int minutes);
    void simulateGoal();
    void simulateYellowCard();
    void simulateRedCard();
    void simulateInjury();
    void simulateSubstitution();
    void startPenaltySimulation();

    std::string date;
    MatchStage stage;
    std::pair<std::shared_ptr<NationalTeam>, std::shared_ptr<NationalTeam>> national_team;
    std::pair<Squad, Squad> squad;
    MatchStatistics statistics;
    std::pair<int, int> overall_addition;
    bool finished;
};
