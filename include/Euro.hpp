#pragma once

#include "Group.hpp"
#include "Schedule.hpp"

/**
 * @brief Class representing the Euro football tournament.
 */
class Euro
{
public:
    /**
     * @brief Constructor for Euro class.
     */
    Euro();
    /**
     * @brief Gets the national team with the specified country name.
     *
     * @param country_name The name of the country.
     * @return A shared pointer to the NationalTeam object.
     */
    [[nodiscard]] auto getNationalTeam(Nationality country_name) const -> std::shared_ptr<NationalTeam>;
    /**
     * @brief Gets the group with the specified name.
     *
     * @param group_name The name of the group.
     * @return A shared pointer to the Group object.
     */
    [[nodiscard]] auto getGroup(const std::string &group_name) const -> std::shared_ptr<Group>;
    /**
     * @brief Displays the name of the Euro tournament.
     */
    void showName() const;
    /**
     * @brief Displays the start date of the Euro tournament.
     */
    void showStartDate() const;
    /**
     * @brief Gets the schedule of matches for the Euro tournament.
     *
     * @return The Schedule object representing the schedule of matches.
     */
    [[nodiscard]] auto getSchedule() const -> Schedule;
    /**
     * @brief Starts the Euro tournament.
     */
    void start();
    /**
     * @brief Displays all members (national teams) participating in the Euro tournament.
     */
    void showAllMembers() const;

private:
    static void showMenu();
    [[nodiscard]] static auto loadNationalTeams() -> std::vector<NationalTeam>;
    auto loadGroups() -> std::vector<Group>;
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
