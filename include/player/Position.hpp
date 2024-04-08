#pragma once

#include <iostream>

#include "utils/TextUtils.hpp"

enum class Position
{
    Goalkeeper,
    Defender,
    Midfielder,
    Attacker
};

namespace position_utils
{
    inline auto positionToString(const Position position) -> std::string
    {
        switch (position)
        {
            case Position::Goalkeeper:
                return "goalkeeper";
            case Position::Defender:
                return "defender";
            case Position::Midfielder:
                return "midfielder";
            case Position::Attacker:
                return "attacker";
        }
        std::cerr << "Error: Invalid position." << std::endl;
        exit(1);
    }

    inline auto stringToPosition(std::string position) -> Position
    {
        text_utils::stringToLower(position);
        if (position == "goalkeeper")
            return Position::Goalkeeper;
        if (position == "defender")
            return Position::Defender;
        if (position == "midfielder")
            return Position::Midfielder;
        if (position == "attacker")
            return Position::Attacker;
        std::cerr << "Error: Invalid position." << std::endl;
        exit(1);
    }
}
