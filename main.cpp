#include <iomanip>
#include <iostream>
#include <string>
#include "db.hpp"
#include "menu.hpp"
#include "student.hpp"

int main() {
    Db bd2;

    Menu MyMenu(
        "+----------------------------------+\n"
        "+ Academic Students Database +\n"
        "+----------------------------------+\n");

    MyMenu.addItem("Add student");
    MyMenu.addItem("Print all students");
    MyMenu.addItem("Search by surname");
    MyMenu.addItem("Search by PESEL");
    MyMenu.addItem("Sort by surname");
    MyMenu.addItem("Sort by PESEL");
    MyMenu.addItem("Delete student");
    MyMenu.addItem("Save to file");
    MyMenu.addItem("Read from file");
    MyMenu.addItem("Exit");

    while (MyMenu.getDoNotExit()) {
        switch (MyMenu.printMenu()) {
        case 1:
            MyMenu.printHeader();
            bd2.addStudent();
            MyMenu.printContinue();
            break;
        case 2:
            MyMenu.printHeader();
            bd2.printDb();
            MyMenu.printContinue();
            break;
        case 3:
            MyMenu.printHeader();
            bd2.searchSurnameInMenu();
            MyMenu.printContinue();
            break;
        case 4:
            MyMenu.printHeader();
            bd2.searchPeselInMenu(); 
            MyMenu.printContinue();
            break;
        case 5:
            MyMenu.optNotImplemented();
            break;
        case 6:
            MyMenu.optNotImplemented();
            break;
        case 7:
            MyMenu.optNotImplemented();
            break;
        case 8:
            MyMenu.optNotImplemented();
            break;
        case 9:
            MyMenu.optNotImplemented();
            break;
        case 10:
            MyMenu.setDoNotExit(false);
            break;
        }
    }
    return 0;
}
