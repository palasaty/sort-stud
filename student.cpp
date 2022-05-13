#include "student.h"
#include <iostream>
#include <ostream>
#include <istream>

std::ostream& operator <<(std::ostream& out, const Date& d)
{
    const std::string delim = ".";
    out << d.day << delim << d.month << delim << d.year;
    return out;
}

std::istream& operator >>(std::istream& in, Date& d)
{
    in >> d.day >> d.month >> d.year;
    return in;
}

std::ostream& operator <<(std::ostream& out, const Student& st)
{
    const std::string delim = "  ";
    out << st.name << delim << st.middleName << delim << st.surname << delim << st.birthDate << delim
        << st.enterYear << delim << st.faculty << delim << st.department << delim << st.group << delim
        << st.gradeBookNo << delim << st.sex;
    return out;
}

std::istream& operator >>(std::istream& in, Student& st)
{
    in >> st.name >> st.middleName >> st.surname >> st.birthDate >> st.enterYear >> st.faculty >> st.department >> st.group
        >> st.gradeBookNo >> st.sex;
    return in;
}

void Student::init() {
    std::cout << "Name: "; std::cin >> name;
    std::cout << "Middle name: "; std::cin >> middleName;
    std::cout << "Surname: "; std::cin >> surname;
    std::cout << "Birth year: "; std::cin >> birthDate.year;
    std::cout << "Birth month: "; std::cin >> birthDate.month;
    std::cout << "Birth day: "; std::cin >> birthDate.day;
    std::cout << "Enter year: "; std::cin >> enterYear;
    std::cout << "Faculty: "; std::cin >> faculty;
    std::cout << "Department: "; std::cin >> department;
    std::cout << "Group: "; std::cin >> group;
    std::cout << "GradeBookNo: "; std::cin >> gradeBookNo;
    std::cout << "Sex: "; std::cin >> sex;
    
    int session_n;
    std::cout << "Session count: "; std::cin >> session_n;
    for (int i = 0; i < session_n; ++i) {
        int subject_n;
        std::cout << "Subjects count: "; std::cin >> subject_n;
        for (int j = 0; j < subject_n; ++j) {
            std::string name;
            int grade;
            std::cout << "Subject name: "; std::cin >> name;
            std::cout << "Grade:"; std::cin >> grade;
            grades[i][name] = grade;
        }
    }
}

void printEditMenu()
{
    std::cout << "Choose which info you want to edit\n"
        << "1. Name\n"
        << "2. Middle name\n"
        << "3. Surname\n"
        << "4. Birth date\n"
        << "5. Enter year\n"
        << "6. Faculty\n"
        << "7. Department\n"
        << "8. Group\n"
        << "9. Sex\n"
        << "10. Grades\n"
        << "11. Exit\n";
}

void printBirhDateMenu() {
    std::cout << "Choose which info you want to edit\n"
        << "1. Day\n"
        << "2. Month\n"
        << "3. Year\n"
        << "4. Exit\n";
}

void printGradesMenu() {
    std::cout << "Choose which info you want to edit\n"
        << "1. Update grade on subject\n"
        << "2. New subject\n"
        << "3. Delete subject\n"
        << "4. Exit\n";
}

void Student::editBirthDate() {
    bool go = true;
    int answer;
    while (go) {
        printBirhDateMenu();
        std::cin >> answer;
        switch (answer) {
            case 4: go = false; break;
            case 1: std::cout << "Birth day: "; std::cin >> birthDate.day; break;
            case 2: std::cout << "Birth month: "; std::cin >> birthDate.month; break;
            case 3: std::cout << "Birth year: "; std::cin >> birthDate.year; break;
            default:
                std::cout << "Unknown answer\n";
        }
    }
}

void Student::editGrades() {
    bool go = true;
    int session, answer;
    std::string subject; 
    int grade;
    while (go) {
        subject.assign("");
        std::cout << "Choose session: "; std::cin >> session;
        if (session < 0 || session >= grades.size())
            continue;
        printGradesMenu();
        std::cin >> answer;
        switch (answer) {
            case 4: go = false; break;
            case 2:
            case 1: {
                std::cout << "Subject: "; std::cin >> subject;
                std::cout << "Grade: "; std::cin >> grade;
                grades[session][subject] = grade;
                break;
            }
            case 3: {
                std::cout << "Subject: "; std::cin >> subject;
                auto& mp = grades[session];
                auto it = mp.find(subject);
                if (it != mp.end()) 
                    mp.erase(it);
                break;
            }
            default:
                std::cout << "Unknown answer\n";

        }
    }
}

void Student::edit() {

    int answer;
    bool go = true;

    while (go) {
        printEditMenu();
        std::cin >> answer;

        switch (answer) {
            case 11: go = false; break;
            case 1: std::cout << "New name: "; std::cin >> name; break;
            case 2: std::cout << "New middle name: "; std::cin >> middleName; break;
            case 3: std::cout << "New surname: "; std::cin >> surname; break;
            case 5: std::cout << "New enter year: "; std::cin >> enterYear; break;
            case 6: std::cout << "New faculty: "; std::cin >> faculty; break;
            case 7: std::cout << "New department: "; std::cin >> department; break;
            case 8: std::cout << "New group: "; std::cin >> group; break;
            case 9: std::cout << "New sex: "; std::cin >> sex; break;
            case 4: editBirthDate(); break;
            case 10: editGrades(); break;
            default:
                std::cout << "Unknown answer\n";

        }
    }
}