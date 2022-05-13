#pragma once

#include <string>
#include <vector>
#include <map>

struct Date {
    int year;
    int month;
    int day;
};

std::ostream& operator <<(std::ostream& out, const Date& d);
std::istream& operator >>(std::istream& in, Date& d);


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
    std::string sex;
    std::vector<std::map<std::string, int>> grades;
};

std::ostream& operator <<(std::ostream& out, const Student& st);
std::istream& operator >>(std::istream& in, Student& st);
