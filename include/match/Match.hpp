#pragma once

#include "MatchStatistics.hpp"
#include "national_team/NationalTeam.hpp"

#include <memory>
#include <string>

class Match
{
public:
    Match(std::string new_date, MatchStage new_stage,
          const std::array<std::shared_ptr<NationalTeam>, 2> &new_national_team);
    void simulate();
    void showResult() const;
    void showSquads() const;
    void showStatistics() const;
    [[nodiscard]] auto isFinished() const->bool;

private:
    [[nodiscard]] auto calculateOverallAddition() const -> std::pair<int, int>;
    void showStage() const;
    void startSimulation(int minutes);
    void simulateGoal();
    void simulateYellowCard();
    void simulateRedCard();
    void simulateInjury();
    void simulateSubstitution();
    void selectGoalScorer(int team_index) const;
    void selectWhoGetsYellowCard(int team_index) const;
    void selectWhoGetsRedCard(int team_index) const;
    void saveCleanSheets() const;
    [[nodiscard]] static auto getPenalityResult() -> std::array<int, 2>;
    void assignPoints() const;
    void assignNextStageToWinner(std::array<int, 2> penalty_result) const;

    std::string date;
    MatchStage stage;
    std::array<std::shared_ptr<NationalTeam>, 2> national_teams;
    std::array<Squad, 2> squads;
    MatchStatistics statistics;
    std::pair<int, int> overall_addition;
    bool finished;
};
