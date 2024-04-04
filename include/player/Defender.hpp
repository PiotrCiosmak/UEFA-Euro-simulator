#pragma once

#include "player/Player.hpp"

class Defender final : public Player
{
public:
    Defender(std::string new_first_name, std::string new_last_name, int new_overall,
             Nationality new_nationality, int new_clean_sheets);

    [[nodiscard]] auto getCleanSheets() const -> int;

private:
    int clean_sheets;
};
