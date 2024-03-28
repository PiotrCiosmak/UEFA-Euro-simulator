#pragma once

#include <string>

class Injury
{
public:
    Injury(bool new_injured = false, int new_days_to_recovery = 0);
    auto isInjured() -> bool;
    auto getDaysToRecovery() -> int;
    auto returnDate() -> std::string;
    void setDaysToRecovery(int new_days_to_recovery);

private:
    bool injured;
    int days_to_recovery;
};