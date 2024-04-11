#pragma once

/**
 * @brief Structure representing statistics of a player.
 */
struct PlayerStatistics
{
    int goals{0}; ///< Number of goals scored by the player.
    int assists{0}; ///< Number of assists made by the player.
    int clean_sheets{0}; ///< Number of clean sheets achieved by the player.
    int yellow_cards{0}; ///< Number of yellow cards received by the player.
    int red_cards{0}; ///< Number of red cards received by the player.
};
