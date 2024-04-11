#pragma once

#include <string>

/**
 * @brief Class representing an injury.
 */

class Injury
{
public:
    /**
     * @brief Default constructor for Injury class.
     */
    Injury();
    /**
     * @brief Constructor for Injury class with parameters.
     *
     * @param new_injured Indicates if the player is injured or not.
     * @param new_days_to_recovery The number of days needed for recovery.
     */
    Injury(bool new_injured, int new_days_to_recovery);
    /**
     * @brief Checks if the player is injured.
     *
     * @return true if the player is injured, false otherwise.
     */
    [[nodiscard]] auto isInjured() const -> bool;
    /**
     * @brief Gets the number of days needed for recovery.
     *
     * @return The number of days needed for recovery.
     */
    [[nodiscard]] auto getDaysToRecovery() const -> int;
    /**
     * @brief Gets the return date after recovery.
     *
     * @return A string representing the return date after recovery.
     */
    [[nodiscard]] auto getReturnDate() const -> std::string;
    /**
     * @brief Sets the number of days needed for recovery.
     *
     * @param new_days_to_recovery The new number of days needed for recovery.
     */
    void setDaysToRecovery(int new_days_to_recovery);

private:
    bool injured;
    int days_to_recovery;
};
