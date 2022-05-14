#include "students.h"
#include <iostream>
#include <sstream>
#include <algorithm>

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

    in.close();
}

void Students::save() {
    std::ofstream out(gFileName);
    if (out.is_open()) {
        for (const auto& st : _database)
        {
            out << st.second << '\n';
        }
        out.close();
    }
    else
        std::cout << "Can't open file" << std::endl;
}

void Students::print() {
    if (_database.empty()) {
        std::cout << "Nothing to print\n";
        return;
    }

    for (const auto& st : _database) {
        st.second.print();
    }
}

void Students::addStudent(Student& st) {
    long id = st.gradeBookNo;
    auto it = _database.find(id);
    if (it != _database.end()) {
        std::cout << "Student with such id '" << id << "' aldready exist\n";
        return;
    }

    _database[id] = st;
}

void Students::addStudent() {
    Student st;
    st.init();
    addStudent(st);
}

void Students::editStudent() {
    int id;
    std::cout << "Enter No to edit: "; std::cin >> id;
    auto it = _database.find(id);
    if (it == _database.end()) {
        std::cout << "No such student\n";
        return;
    }

    auto& st = getStudent(id);

    st.edit();
}

void Students::removeStudent() {
    int id;
    std::cout << "Enter No to remove: "; std::cin >> id;

    auto it = _database.find(id);
    if (it != _database.end())
        _database.erase(it);
    else {
        std::cout << "No such student\n";
    }
}

void Students::customSort()
{
    int idx;
    std::cout << "Sesion: "; std::cin >> idx;
    int yearMin, yearMax;
    std::cout << "Min birth year: "; std::cin >> yearMin;
    std::cout << "Max birth year: "; std::cin >> yearMax;

    std::vector<Student> filtered;

    for (auto& p : _database) {
        if (p.second.birthDate.year >= yearMin && p.second.birthDate.year <= yearMax) {
            filtered.push_back(p.second);
        }
    }

    std::sort(filtered.begin(), filtered.end(), [&](const Student& st1, const Student& st2) {
            return st1.avgGrade(idx) < st2.avgGrade(idx);
        });

    for (const auto& st : filtered) {
        st.print();
    }
}