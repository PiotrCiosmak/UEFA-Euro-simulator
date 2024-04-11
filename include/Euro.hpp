#pragma once

#include "Group.hpp"
#include "Schedule.hpp"

class Euro
{
public:
    Euro();
    [[nodiscard]] auto getNationalTeam(Nationality country_name) const -> std::shared_ptr<NationalTeam>;
    [[nodiscard]] auto getGroup(const std::string &group_name) const -> std::shared_ptr<Group>;
    void showName() const;
    void showStartDate() const;
    [[nodiscard]] auto getSchedule() const -> Schedule;
    void start();
    void showAllMembers() const;

private:
    static void showMenu();
    [[nodiscard]] static auto loadNationalTeams()->std::vector<NationalTeam>;
    auto loadGroups() ->std::vector<Group>;
    void showWinner() const;
    static void invalidOption();
    static void close();

    std::string name;
    std::vector<NationalTeam> national_teams;
    Schedule schedule;
    std::vector<Group> groups;
    std::string start_date;
    std::shared_ptr<NationalTeam> winner;
};
