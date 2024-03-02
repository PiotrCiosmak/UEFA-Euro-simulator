#pragma once

class Injury
{
public:
    explicit Injury(bool new_acitve = false, int new_remaining_days = 0);

private:
    bool active;
    int remaining_days;
};
