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
    float avgGrade(int session) const;

public:
    int enterYear;
    std::string faculty;
    std::string department;
    int group;
    long gradeBookNo;
    SessionGrades grades;

private:
    void editBirthDate();
    void editGrades();
};

std::ostream& operator <<(std::ostream& out, const Student& st);
std::istream& operator >>(std::istream& in, Student& st);
