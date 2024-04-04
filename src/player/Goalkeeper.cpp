#include "player/Goalkeeper.hpp"

Goalkeeper::Goalkeeper(std::string new_first_name, std::string new_last_name, const int new_overall,
                       const Nationality new_nationality, const int new_clean_sheets) : Player{
    std::move(new_first_name),
    std::move(new_last_name), new_overall,
    new_nationality
}, clean_sheets{new_clean_sheets}
{
}

auto Goalkeeper::getCleanSheets() const -> int
{
    return clean_sheets;
}
