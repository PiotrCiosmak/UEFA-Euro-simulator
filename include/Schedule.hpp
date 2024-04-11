#pragma once

#include "MatchStage.hpp"
#include "match/Match.hpp"

class Schedule
{
public:
    explicit Schedule(const std::vector<NationalTeam> &national_teams);
    void show(MatchStage match_stage) const;
    void playNextMatch();
    void showNextMatch() const;

private:
    [[nodiscard]] static auto loadGroupStage(const std::vector<NationalTeam>& national_teams) ->std::vector<Match>;
    void generateNextKnockoutStage();

    std::vector<Match> matches;
    static int matches_played;
};
