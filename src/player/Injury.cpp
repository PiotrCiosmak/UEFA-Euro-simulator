#include "player/Injury.hpp"

#include <chrono>

Injury::Injury(): injured{false}, days_to_recovery{0}
{
}

Injury::Injury(const bool new_injured, const int new_days_to_recovery) : injured{new_injured},
                                                                         days_to_recovery{new_days_to_recovery}
{
}

auto Injury::isInjured() const -> bool
{
    return injured;
}

auto Injury::getDaysToRecovery() const -> int
{
    return days_to_recovery;
}

auto Injury::getReturnDate() const -> std::string
{
    const auto today = std::chrono::system_clock::now();
    const auto recovery_date = today + std::chrono::hours(24 * days_to_recovery);
    const auto recovery_time = std::chrono::system_clock::to_time_t(recovery_date);
    std::stringstream ss;
    ss << std::ctime(&recovery_time);
    return ss.str();
}

void Injury::setDaysToRecovery(const int new_days_to_recovery)
{
    //TODO fix injury (every day in sim decrement days_to_recover if 0 set it to false)
    this->injured = true;
    this->days_to_recovery = new_days_to_recovery;
}
