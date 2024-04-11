#pragma once

#include "MatchStage.hpp"
#include "match/Match.hpp"

/**
 * @brief Class representing the schedule of matches in a football tournament.
 */
class Schedule
{
public:
    /**
     * @brief Constructor for Schedule class.
     *
     * @param national_teams A vector of NationalTeam objects representing all participating national teams.
     */
    explicit Schedule(const std::vector<NationalTeam> &national_teams);
    /**
     * @brief Displays the matches in the schedule for the specified match stage.
     *
     * @param match_stage The stage of the match (group stage or knockout stage).
     */
    void show(MatchStage match_stage) const;
    /**
     * @brief Plays the next match in the schedule.
     */
    void playNextMatch();
    /**
     * @brief Displays information about the next match in the schedule.
     */
    void showNextMatch() const;

private:
    [[nodiscard]] static auto loadGroupStage(const std::vector<NationalTeam> &national_teams) -> std::vector<Match>;
    void generateNextKnockoutStage();

    std::vector<Match> matches;
    static int matches_played;
};
