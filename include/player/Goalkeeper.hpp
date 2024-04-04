#pragma once

#include "Player.hpp"

class Goalkeeper final : public Player
{
public:
    Goalkeeper(std::string new_first_name, std::string new_last_name, int new_overall,
               Nationality new_nationality, int clean_sheets);

    [[nodiscard]] auto getCleanSheets() const -> int;

private:
    int clean_sheets;
};
