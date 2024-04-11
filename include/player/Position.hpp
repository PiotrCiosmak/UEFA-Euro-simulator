#pragma once

#include "utils/TextUtils.hpp"

#include <iostream>

/**
 * @brief Enumeration representing player positions.
 */
enum class Position
{
    Goalkeeper, ///< Goalkeeper position.
    Defender, ///< Defender position.
    Midfielder, ///< Midfielder position.
    Attacker ///< Attacker position.
};

namespace position_utils
{
    /**
    * @brief Converts a Position enum value to its string representation.
    *
    * @param position The Position enum value.
    * @return A string representing the given position.
    */
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

    /**
    * @brief Converts a string representation of a position to the corresponding Position enum value.
    *
    * @param position A string representing the position.
    * @return The Position enum value corresponding to the given string.
    */
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
