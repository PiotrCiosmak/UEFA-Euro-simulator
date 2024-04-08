#pragma once

#include <string>

class Injury
{
public:
    Injury();
    Injury(bool new_injured, int new_days_to_recovery);
    [[nodiscard]] auto isInjured() const -> bool;
    [[nodiscard]] auto getDaysToRecovery() const -> int;
    [[nodiscard]] auto getReturnDate() const -> std::string;
    void setDaysToRecovery(int new_days_to_recovery);

private:
    bool injured;
    int days_to_recovery;
};
