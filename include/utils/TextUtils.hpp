#pragma once

#include <string>
#include <algorithm>

namespace text_utils
{
    /**
     * @brief Converts a string to lowercase.
     *
     * @param line The string to be converted to lowercase.
     */
    inline void stringToLower(std::string &line)
    {
        std::ranges::transform(line.begin(), line.end(), line.begin(),
                               [](const unsigned char c) { return std::tolower(c); });
    }
}
