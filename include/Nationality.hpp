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
    inline auto nationalityToString(const Nationality nationality, bool tolower = false) -> std::string
    {
        std::string country_name;
        switch (nationality)
        {
            case Nationality::Germany:
                country_name = "Germany";
                break;
            case Nationality::Spain:
                country_name = "Spain";
                break;
            case Nationality::France:
                country_name = "France";
                break;
            case Nationality::England:
                country_name = "England";
                break;
            case Nationality::Turkey:
                country_name = "Turkey";
                break;
            case Nationality::Albania:
                country_name = "Albania";
                break;
            case Nationality::Belgium:
                country_name = "Belgium";
                break;
            case Nationality::Hungary:
                country_name = "Hungary";
                break;
            case Nationality::Denmark:
                country_name = "Denmark";
                break;
            case Nationality::Romania:
                country_name = "Romania";
                break;
            case Nationality::Portugal:
                country_name = "Portugal";
                break;
            case Nationality::Scotland:
                country_name = "Scotland";
                break;
            case Nationality::Netherlands:
                country_name = "Netherlands";
                break;
            case Nationality::Italy:
                country_name = "Italy";
                break;
            case Nationality::Croatia:
                country_name = "Croatia";
                break;
            case Nationality::CzechRepublic:
                country_name = "Czech Republic";
                break;
            case Nationality::Austria:
                country_name = "Austria";
                break;
            case Nationality::Serbia:
                country_name = "Serbia";
                break;
            case Nationality::Slovenia:
                country_name = "Slovenia";
                break;
            case Nationality::Switzerland:
                country_name = "Switzerland";
                break;
            case Nationality::Slovakia:
                country_name = "Slovakia";
                break;
            case Nationality::Poland:
                country_name = "Poland";
                break;
            case Nationality::Ukraine:
                country_name = "Ukraine";
                break;
            case Nationality::Georgia:
                country_name = "Georgia";
                break;
            default:
                std::cerr << "Error: Invalid nationality." << std::endl;
                exit(1);
        }
        if (tolower)
        {
            if (country_name == "Czech Republic")
            {
                country_name = "Czech_Republic";
            }
            text_utils::stringToLower(country_name);
        }
        return country_name;
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
