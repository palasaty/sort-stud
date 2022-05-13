#include "student.h"
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
    out << st.name << delim << st.surname << delim << st.middleName << delim << st.birthDate << delim
        << st.enterYear << delim << st.faculty << delim << st.department << delim << st.group << delim
        << st.gradeBookNo << delim << st.sex;
    return out;
}

std::istream& operator >>(std::istream& in, Student& st)
{
    in >> st.name >> st.surname >> st.middleName >> st.birthDate >> st.enterYear >> st.faculty >> st.department >> st.group
        >> st.gradeBookNo >> st.sex;
    return in;
}