#pragma once

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

std::string countryToString(const Nationality nationality)
{
    switch (nationality)
    {
        case Nationality::Germany: return "Germany";
        case Nationality::Spain: return "Spain";
        case Nationality::France: return "France";
        case Nationality::England: return "England";
        case Nationality::Turkey: return "Turkey";
        case Nationality::Albania: return "Albania";
        case Nationality::Belgium: return "Belgium";
        case Nationality::Hungary: return "Hungary";
        case Nationality::Denmark: return "Denmark";
        case Nationality::Romania: return "Romania";
        case Nationality::Portugal: return "Portugal";
        case Nationality::Scotland: return "Scotland";
        case Nationality::Netherlands: return "Netherlands";
        case Nationality::Italy: return "Italy";
        case Nationality::Croatia: return "Croatia";
        case Nationality::CzechRepublic: return "Czech Republic";
        case Nationality::Austria: return "Austria";
        case Nationality::Serbia: return "Serbia";
        case Nationality::Slovenia: return "Slovenia";
        case Nationality::Switzerland: return "Switzerland";
        case Nationality::Slovakia: return "Slovakia";
        case Nationality::Poland: return "Poland";
        case Nationality::Ukraine: return "Ukraine";
        case Nationality::Georgia: return "Georgia";
        default: return "Unknown";
    }
}
