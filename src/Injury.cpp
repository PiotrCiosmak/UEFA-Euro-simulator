#include "Injury.hpp"

#include <chrono>

Injury::Injury(bool new_injured, int new_days_to_recovery) : injured{new_injured},
                                                             days_to_recovery{new_days_to_recovery}
{}

auto Injury::isInjured() -> bool
{
    return injured;
}

auto Injury::getDaysToRecovery() -> int
{
    return days_to_recovery;
}

auto Injury::returnDate() -> std::string
{
    auto today = std::chrono::system_clock::now();
    auto recovery_date = today + std::chrono::hours(24 * days_to_recovery);
    auto recovery_time = std::chrono::system_clock::to_time_t(recovery_date);
    std::stringstream ss;
    ss << std::ctime(&recovery_time);

    return ss.str();
}

void Injury::setDaysToRecovery(int new_days_to_recovery)
{
    this->days_to_recovery = new_days_to_recovery;
}