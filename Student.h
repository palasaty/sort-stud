#pragma once

#include <string>
#include <vector>
#include <map>

struct Date {
    int year;
    int month;
    int day;
};

struct Student {
    std::string name;
    std::string surname;
    std::string middleName;
    Date birthDate;
    int enterYear;
    std::string faculty;
    std::string department;
    int group;
    long gradeBookNo;
    bool sex;
    std::vector<std::map<std::string, int>> grades;
};