#include "student.h"
#include <iostream>
#include <ostream>
#include <istream>

std::ostream& operator <<(std::ostream& out, const Date& d)
{
    const std::string delim = "  ";
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
        << st.gradeBookNo << delim << st.sex << delim;

    out << st.grades.size() << delim;
    for (auto& s : st.grades) {
        out << s.size() << delim;
        for (auto& sbj : s) {
            out << sbj.first << delim << sbj.second << delim;
        }
    }
    return out;
}

void Student::print() const {
    std::cout << "==============================================================\n";
    std::cout << "Name: " << name << "\tMiddleName: " << middleName << "\tSurname: " << surname << "\n";
    std::cout << "Birth date: " << birthDate.toString() << "\n";
    std::cout << "Sex: " << (sex ? "man" : "woman") << "\n";
    std::cout << "Faculty: " << faculty << "\tDepartment: " << department << "\tGroup: " << group << "\n";
    std::cout << "Enter year: " << enterYear << "\n";
    std::cout << "Grade book #: " << gradeBookNo << "\n";
    std::cout << "==============================================================\n";

    for (int i = 0; i < grades.size(); ++i) {
        std::cout << "Session " << i + 1 << ": \n";
        for (auto& sbj : grades[i]) {
            std::cout << "Subject: " << sbj.first << "\tGrade: " << sbj.second << "\n";
        }
    }
    std::cout << "==============================================================\n\n";

}

std::istream& operator >>(std::istream& in, Student& st)
{
    in >> st.name >> st.middleName >> st.surname >> st.birthDate >> st.enterYear >> st.faculty >> st.department >> st.group
        >> st.gradeBookNo >> st.sex;
    int s_size, sbj_size;
    in >> s_size;
    for (int i = 0; i < s_size; ++i) {
        st.grades.push_back(Student::Grades());
        in >> sbj_size;
        for (int j = 0; j < sbj_size; ++j) {
            std::string sbj;
            int grade;
            in >> sbj >> grade;
            st.grades[i][sbj] = grade;
        }

    }
    return in;
}

bool Student::checkSession(int s) const {
    if (s < 0 || s >= grades.size()) {
        std::cout << "Incorrect session number\n";
        return false;
    }

    return true;
}

float Student::avgGrade(int session) const {
    int cnt = 0;
    float res = 0;
    for (auto& sbj : grades[session]) {
        cnt++;
        res += sbj.second;
    }

    return res / cnt;
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
        grades.push_back(Grades());
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