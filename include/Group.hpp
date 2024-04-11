#pragma once

#include "national_team/NationalTeam.hpp"

#include <array>

/**
 * @brief Class representing a group in a football tournament.
 */
class Group
{
public:
    /**
     * @brief Constructor for Group class.
     *
     * @param new_name The name of the group.
     * @param new_national_teams An array of shared pointers to NationalTeam objects representing the teams in the group.
     */
    Group(std::string new_name, const std::array<std::shared_ptr<NationalTeam>, 4> &new_national_teams);
    /**
     * @brief Gets the teams in the group.
     *
     * @return An array of shared pointers to NationalTeam objects representing the teams in the group.
     */
    [[nodiscard]] auto getTeams() const -> std::array<std::shared_ptr<NationalTeam>, 4>;
    /**
     * @brief Gets the name of the group.
     *
     * @return The name of the group.
     */
    [[nodiscard]] auto getName() const -> std::string;
    /**
     * @brief Displays the table of the group.
     */
    void showTable() const;

private:
    [[nodiscard]] auto sortNationalTeams() const -> std::array<std::shared_ptr<NationalTeam>, 4>;

    std::string name;
    std::array<std::shared_ptr<NationalTeam>, 4> national_teams;
    constexpr static int max_teams = 4;
};
