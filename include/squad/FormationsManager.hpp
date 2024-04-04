#pragma once

#include <string>
#include <vector>

class FormationsManager
{
public:
    FormationsManager(const FormationsManager &) = delete;
    FormationsManager(FormationsManager &&) = delete;
    static FormationsManager *instance();
    void showAll() const;

private:
    FormationsManager();
    std::vector<std::string> formations;
};
