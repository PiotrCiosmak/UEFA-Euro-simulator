#include "squad/FormationsManager.hpp"

#include <fstream>
#include <iostream>

FormationsManager *FormationsManager::instance()
{
    static FormationsManager formations_manager;
    return &formations_manager;
}

void FormationsManager::showAll() const
{
    for (int i = 0; i < formations.size(); ++i)
    {
        std::cout << i + 1 << ". " << formations.at(i) << std::endl;
    }
}

FormationsManager::FormationsManager()
{
    const auto file_name = "formations.csv";
    std::ifstream file{file_name};
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            formations.push_back(line);
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file " << file_name << std::endl;
        exit(1);
    }
}
