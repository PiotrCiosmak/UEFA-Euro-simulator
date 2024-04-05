#pragma once

enum class Position
{
    Goalkeeper,
    Defender,
    Midfielder,
    Attacker
};

std::string positionToString(const Position position)
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
        default:
            return "Unknown";
    }
}
