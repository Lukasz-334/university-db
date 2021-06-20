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
        "+    Academic Students Database    +\n"
        "+----------------------------------+\n");

    MyMenu.addItem("Add student");
    MyMenu.addItem("Print all students");
    MyMenu.addItem("Search by surname");
    MyMenu.addItem("Search by PESEL");
    MyMenu.addItem("Sort by surname");
    MyMenu.addItem("Sort by PESEL");
    MyMenu.addItem("Delete student");
    MyMenu.addItem("Save DB to file");
    MyMenu.addItem("Load DB from file");
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
            MyMenu.printHeader();
            bd2.sortSurname();
            MyMenu.printContinue();
            break;
        case 6:
            MyMenu.printHeader();
            bd2.sortPesel();
            MyMenu.printContinue();
            break;
        case 7:
            MyMenu.printHeader();
            bd2.deleteStudInMenu();
            MyMenu.printContinue();
            break;
        case 8:
            MyMenu.printHeader();
            bd2.saveDbToFile("db.dat");
            MyMenu.printContinue();
            break;
        case 9:
            MyMenu.printHeader();
            bd2.loadDbFromFile("db.dat");
            MyMenu.printContinue();
            break;
        case 10:
            MyMenu.setDoNotExit(false);
            break;
        }
    }
    return 0;
}
