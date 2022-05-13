
#include <iostream>
#include "students.h"

void printMenu() {
    std::cout
        << "1. Print all\n"
        << "2. Add student\n"
        << "3. Edit student\n"
        << "4. Remove student\n"
        << "5. Print sorted\n"
        << "6. Exit\n";
}


int main()
{
    Students students;

    int answer;
    bool go = true;
    while (go) {
        printMenu();
        std::cin >> answer;

        switch (answer) {
        case 6: go = false; break;
        case 1: students.print(); break;
        case 2: students.addStudent(); break;
        case 3: students.editStudent(); break;
        case 4: students.removeStudent(); break;
        case 5:students.customSort(); break;
        default:
            std::cout << "Unknown command\n";

        }
    }

    return 0;
}

