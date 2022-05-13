#include "students.h"
#include <iostream>;
#include <sstream>

void Students::load() {
    std::ifstream in(gFileName);
    if (!in.is_open()) {
        std::cout << "File isn't exist yet\n";
    }
    
    std::string line;

    Student st;
    while (getline(in, line))
    {
        std::istringstream iss(line);
        iss >> st;
        _database[st.gradeBookNo] = st;
    }
}

void Students::save() {
    std::ofstream out(gFileName);
    if (out.is_open())
        for (const auto& st : _database)
        {
            out << st.second << '\n';
        }
    else
        std::cout << "Can't open file" << std::endl;
}

void Students::print() {
    for (const auto& st : _database) {
        std::cout << st.second << "\n";
    }
}