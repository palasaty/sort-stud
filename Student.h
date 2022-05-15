#pragma once

#include <string>
#include <vector>
#include <map>
#include <sstream>

struct Date {
    int year;
    int month;
    int day;

    std::string toString() const {
        std::stringstream ss;
        ss << day << "." << month << "." << year;
        return ss.str();
    }
};

std::ostream& operator <<(std::ostream& out, const Date& d);
std::istream& operator >>(std::istream& in, Date& d);

struct Person {
    std::string name;
    std::string surname;
    std::string middleName;
    Date birthDate;
    bool sex; // 1 - M, 0 - W
};

struct Student : public Person {
public:
    using Grades = std::map<std::string, int>;
    using SessionGrades = std::vector<Grades>;

public:
    void init();
    void edit();

    void print() const;
    float avgGrade(int session) const;
    bool checkSession(int) const;

public:
    int enterYear;
    std::string faculty;
    std::string department;
    int group;
    int gradeBookNo;
    SessionGrades grades;

private:
    void editBirthDate();
    void editGrades();
};

std::ostream& operator <<(std::ostream& out, const Student& st);
std::istream& operator >>(std::istream& in, Student& st);
