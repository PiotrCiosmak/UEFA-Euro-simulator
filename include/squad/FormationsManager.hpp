#pragma once

#include <string>
#include <vector>

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

    std::vector<std::string> formations;
};
