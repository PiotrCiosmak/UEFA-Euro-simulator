#pragma once

#include "utils/TextUtils.hpp"

#include <iostream>
#include <string>

enum class Nationality
{
    Germany,
    Spain,
    France,
    England,
    Turkey,
    Albania,
    Belgium,
    Hungary,
    Denmark,
    Romania,
    Portugal,
    Scotland,
    Netherlands,
    Italy,
    Croatia,
    CzechRepublic,
    Austria,
    Serbia,
    Slovenia,
    Switzerland,
    Slovakia,
    Poland,
    Ukraine,
    Georgia
};

namespace nationality_utils
{
    inline auto nationalityToString(const Nationality nationality) -> std::string
    {
        switch (nationality)
        {
            case Nationality::Germany:
                return "Germany";
            case Nationality::Spain:
                return "Spain";
            case Nationality::France:
                return "France";
            case Nationality::England:
                return "England";
            case Nationality::Turkey:
                return "Turkey";
            case Nationality::Albania:
                return "Albania";
            case Nationality::Belgium:
                return "Belgium";
            case Nationality::Hungary:
                return "Hungary";
            case Nationality::Denmark:
                return "Denmark";
            case Nationality::Romania:
                return "Romania";
            case Nationality::Portugal:
                return "Portugal";
            case Nationality::Scotland:
                return "Scotland";
            case Nationality::Netherlands:
                return "Netherlands";
            case Nationality::Italy:
                return "Italy";
            case Nationality::Croatia:
                return "Croatia";
            case Nationality::CzechRepublic:
                return "Czech Republic";
            case Nationality::Austria:
                return "Austria";
            case Nationality::Serbia:
                return "Serbia";
            case Nationality::Slovenia:
                return "Slovenia";
            case Nationality::Switzerland:
                return "Switzerland";
            case Nationality::Slovakia:
                return "Slovakia";
            case Nationality::Poland:
                return "Poland";
            case Nationality::Ukraine:
                return "Ukraine";
            case Nationality::Georgia:
                return "Georgia";
        }
        std::cerr << "Error: Invalid nationality." << std::endl;
        exit(1);
    }

    inline auto stringToNationality(std::string nationality) -> Nationality
    {
        text_utils::stringToLower(nationality);
        if (nationality == "germany")
            return Nationality::Germany;
        if (nationality == "spain")
            return Nationality::Spain;
        if (nationality == "france")
            return Nationality::France;
        if (nationality == "england")
            return Nationality::England;
        if (nationality == "turkey")
            return Nationality::Turkey;
        if (nationality == "albania")
            return Nationality::Albania;
        if (nationality == "belgium")
            return Nationality::Belgium;
        if (nationality == "hungary")
            return Nationality::Hungary;
        if (nationality == "denmark")
            return Nationality::Denmark;
        if (nationality == "romania")
            return Nationality::Romania;
        if (nationality == "portugal")
            return Nationality::Portugal;
        if (nationality == "scotland")
            return Nationality::Scotland;
        if (nationality == "netherlands")
            return Nationality::Netherlands;
        if (nationality == "italy")
            return Nationality::Italy;
        if (nationality == "croatia")
            return Nationality::Croatia;
        if (nationality == "czech republic" || nationality == "czechrepublic")
            return Nationality::CzechRepublic;
        if (nationality == "austria")
            return Nationality::Austria;
        if (nationality == "serbia")
            return Nationality::Serbia;
        if (nationality == "slovenia")
            return Nationality::Slovenia;
        if (nationality == "switzerland")
            return Nationality::Switzerland;
        if (nationality == "slovakia")
            return Nationality::Slovakia;
        if (nationality == "poland")
            return Nationality::Poland;
        if (nationality == "ukraine")
            return Nationality::Ukraine;
        if (nationality == "georgia")
            return Nationality::Georgia;
        std::cerr << "Error: Invalid nationality." << std::endl;
        exit(1);
    }
}
