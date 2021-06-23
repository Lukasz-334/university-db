#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include "db.hpp"
#include "menu.hpp"
#include "student.hpp"

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);
    size_t vector_reserve = 10;
    Db bd2(vector_reserve);
    if (args.size() < 2) {
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
    } else {
        if (args[1] != "-t") {
            std::cout << "Wrong arguments.\n"
                      << "Usage:\n"
                      << "    " << args[0] << '\n'
                      << "    " << args[0] << " -t\n";
        } else {
            std::cout << "+--------------------------------------------+\n"
                      << "+           START TEST PROCEDURES:           +\n"
                      << "+--------------------------------------------+\n\n"
                      << "Adding new student to database (corret PESEL):\n";
            Student tmp_stud;
            tmp_stud.setName("Adam");
            tmp_stud.setSurname("Konieczny");
            tmp_stud.setAddress("Warszawa");
            tmp_stud.setIndex("31456");
            tmp_stud.setPesel("47052253642");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("Jan");
            tmp_stud.setSurname("Nowak");
            tmp_stud.setAddress("Sochaczew");
            tmp_stud.setIndex("41532");
            tmp_stud.setPesel("02322962488");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("Marian");
            tmp_stud.setSurname("Konieczny");
            tmp_stud.setAddress("Warszawa");
            tmp_stud.setIndex("34536");
            tmp_stud.setPesel("01241249667");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("Piotr");
            tmp_stud.setSurname("Nowak");
            tmp_stud.setAddress("Wejcherowo");
            tmp_stud.setIndex("28179");
            tmp_stud.setPesel("79051074234");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("Anna");
            tmp_stud.setSurname("Kowalska");
            tmp_stud.setAddress("Strzegowo");
            tmp_stud.setIndex("12245");
            tmp_stud.setPesel("97062537START166");
            tmp_stud.setGender("F");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("John");
            tmp_stud.setSurname("Smith");
            tmp_stud.setAddress("NewYork");
            tmp_stud.setIndex("45231");
            tmp_stud.setPesel("83091644917");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("Marek");
            tmp_stud.setSurname("Konieczny");
            tmp_stud.setAddress("Bydgoszcz");
            tmp_stud.setIndex("45139");
            tmp_stud.setPesel("98010233714");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            tmp_stud.setName("Krzysztof");
            tmp_stud.setSurname("Stanowski");
            tmp_stud.setAddress("Police");
            tmp_stud.setIndex("4739");
            tmp_stud.setPesel("03282974346");
            tmp_stud.setGender("M");
            bd2.addStudent(tmp_stud);
            std::cout << "----------------------------------------------\n";
            std::cout << "Adding new student to database (incorret PESEL):\n";
            tmp_stud.setName("Daria");
            tmp_stud.setSurname("Niebieska");
            tmp_stud.setAddress("Niebo");
            tmp_stud.setIndex("123456");
            tmp_stud.setPesel("570428811111");
            tmp_stud.setGender("F");
            bd2.addStudent(tmp_stud);
            std::cout << "----------------------------------------------\n";
            std::cout << "Printing all elements in database:\n";
            bd2.printDb();
            std::cout << "----------------------------------------------\n";
            std::cout << "Search student by surname 'Stanowski':\n";
            if (bd2.searchSurname("Stanowski")) {
                std::cout << "Not found.\n";
            }
            std::cout << "----------------------------------------------\n";
            std::cout << "Search student by PESEL '79051074234':\n";
            if (bd2.searchPesel("79051074234")) {
                std::cout << "Not found.\n";
            }
            std::cout << "----------------------------------------------\n";
            std::cout << "Delete student by index '4739':\n";
            bd2.deleteStud("4739");
            std::cout << "Delete student by index '28179':\n";
            bd2.deleteStud("28179");
            std::cout << "----------------------------------------------\n";
            std::cout << "Printing all elements in database:\n";
            bd2.printDb();
            std::cout << "----------------------------------------------\n";
            std::cout << "Search student by surname 'Stanowski':\n";
            if (bd2.searchSurname("Stanowski")) {
                std::cout << "Not found.\n";
            }
            std::cout << "----------------------------------------------\n";
            std::cout << "Search student by PESEL '79051074234':\n";
            if (bd2.searchPesel("79051074234")) {
                std::cout << "Not found.\n";
            }
            std::cout << "----------------------------------------------\n";
            std::cout << "Save database to file 'db.dat':\n";
            bd2.saveDbToFile("db.dat");
            std::cout << "----------------------------------------------\n";
            std::cout << "Printing all elements in database:\n";
            bd2.printDb();
            std::cout << "----------------------------------------------\n";
            std::cout << "Sort students by surname:\n";
            bd2.sortSurname();
            std::cout << "----------------------------------------------\n";
            std::cout << "Printing all elements in database:\n";
            bd2.printDb();
            std::cout << "----------------------------------------------\n";
            std::cout << "Load database from file 'db.dat':\n";
            bd2.loadDbFromFile("db.dat");
            std::cout << "----------------------------------------------\n";
            std::cout << "Printing all elements in database:\n";
            bd2.printDb();
            std::cout << "----------------------------------------------\n";
            std::cout << "Sort students by PESEL:\n";
            bd2.sortPesel();
            std::cout << "----------------------------------------------\n";
            std::cout << "Printing all elements in database:\n";
            bd2.printDb();
            std::cout << "+--------------------------------------------+\n"
                      << "+                 TEST ENDED                 +\n"
                      << "+--------------------------------------------+\n\n";
        }
    }
    return 0;
}
