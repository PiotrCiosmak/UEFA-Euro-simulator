#include "Group.hpp"


Group::Group(std::string new_name, const std::array<std::shared_ptr<NationalTeam>, 4> &new_national_teams): name{
    std::move(new_name)
}, national_teams{new_national_teams}
{
}

auto Group::getTeams() const -> std::array<std::shared_ptr<NationalTeam>, 4>
{
    return national_teams;
}

auto Group::getName() const -> std::string
{
    return name;
}

void Group::showTable() const
{
    const auto sorted_national_teams = sortNationalTeams();

    std::cout << name << std::endl;
    auto counter = 0;
    for (const auto &national_team: sorted_national_teams)
    {
        const auto statistics = national_team->getGroupStageStatistics();
        const auto goal_difference = statistics->getGoalsScored() - statistics->getGoalsConceded();
        std::cout << counter << ". " << nationality_utils::nationalityToString(national_team->getCountryName()) <<
                ", points: " << statistics->getPoints() << ", goal difference: " << goal_difference << std::endl;
        counter++;
    }
}

auto Group::sortNationalTeams() const -> std::array<std::shared_ptr<NationalTeam>, 4>
{
    auto compare = [](const std::shared_ptr<NationalTeam> &team_a, const std::shared_ptr<NationalTeam> &team_b)
    {
        const auto team_a_statistics = team_a->getGroupStageStatistics();
        const auto team_b_statistics = team_b->getGroupStageStatistics();
        if (team_a->getGroupStageStatistics() != team_b->getGroupStageStatistics())
        {
            return team_a_statistics->getPoints() > team_b_statistics->getPoints();
        }

        const auto team_a_goal_difference = team_a_statistics->getGoalsScored() - team_a_statistics->getGoalsConceded();
        const auto team_b_goal_difference = team_a_statistics->getGoalsScored() - team_b_statistics->getGoalsConceded();
        if (team_a_goal_difference != team_b_goal_difference)
        {
            return team_a_goal_difference > team_b_goal_difference;
        }

        const auto team_a_goals_scored = team_a_statistics->getGoalsScored();
        const auto team_b_goals_scored = team_b_statistics->getGoalsScored();
        if (team_a_goals_scored != team_b_goals_scored)
        {
            return team_a_goals_scored > team_b_goals_scored;
        }

        const auto team_a_wins = team_a_statistics->getWins();
        const auto team_b_wins = team_b_statistics->getWins();
        if (team_a_wins != team_b_wins)
        {
            return team_a_wins > team_b_wins;
        }

        const auto team_a_fair_play_point = team_a_statistics->getYellowCards() + 2 * team_a_statistics->getRedCards();
        const auto team_b_fair_play_point = team_b_statistics->getYellowCards() + 2 * team_b_statistics->getRedCards();
        if (team_a_fair_play_point != team_b_fair_play_point)
        {
            return team_a_fair_play_point < team_b_fair_play_point;
        }

        return team_a->getPositionInRanking() < team_b->getPositionInRanking();
    };

    std::array<std::shared_ptr<NationalTeam>, 4> sorted_national_teams = national_teams;
    std::ranges::sort(sorted_national_teams, compare);
    return sorted_national_teams;
}
