#pragma once

#include <string>
#include <algorithm>

namespace text_utils
{
    inline void stringToLower(std::string &line)
    {
        std::ranges::transform(line.begin(), line.end(), line.begin(),
                               [](const unsigned char c) { return std::tolower(c); });
    }
}
