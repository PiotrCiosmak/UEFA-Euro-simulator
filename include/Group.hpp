#pragma once

#include "national_team/NationalTeam.hpp"

#include <array>

class Group
{
public:
    Group(std::string new_name, const std::array<std::shared_ptr<NationalTeam>, 4> &new_national_teams);
    [[nodiscard]] auto getTeams() const -> std::array<std::shared_ptr<NationalTeam>, 4>;
    [[nodiscard]] auto getName() const -> std::string;
    void showTable() const;

private:
    [[nodiscard]] auto sortNationalTeams() const -> std::array<std::shared_ptr<NationalTeam>, 4>;

    std::string name;
    std::array<std::shared_ptr<NationalTeam>, 4> national_teams;
    constexpr static auto max_teams = 4;
};
