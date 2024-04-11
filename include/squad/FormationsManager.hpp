#pragma once

#include <string>
#include <array>

/**
 * @brief Class responsible for managing football formations.
 */
class FormationsManager
{
public:
    /**
     * @brief Deleted copy constructor to prevent copying of the instance.
     */
    FormationsManager(const FormationsManager &) = delete;
    /**
     * @brief Deleted move constructor to prevent moving of the instance.
     */
    FormationsManager(FormationsManager &&) = delete;
    /**
     * @brief Static method to access the singleton instance of FormationsManager.
     *
     * @return A pointer to the singleton instance of FormationsManager.
     */
    static FormationsManager *instance();
    /**
     * @brief Displays all available formations.
     *
     * @return The number of formations available.
     */
    [[nodiscard]] auto showAll() const -> size_t;
    /**
     * @brief Gets the formation at the specified index.
     *
     * @param index The index of the formation.
     * @return The formation at the specified index.
     */
    [[nodiscard]] auto getFormation(size_t index) -> std::string;

private:
    FormationsManager();

    std::array<std::string, 31> formations;
};
