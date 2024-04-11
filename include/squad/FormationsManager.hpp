#pragma once

#include <string>
#include <array>

class FormationsManager
{
public:
    FormationsManager(const FormationsManager &) = delete;
    FormationsManager(FormationsManager &&) = delete;
    static FormationsManager *instance();
    [[nodiscard]] auto showAll() const -> size_t;
    [[nodiscard]] auto getFormation(size_t index) -> std::string;
private:
    FormationsManager();

    std::array<std::string, 31> formations;
};
