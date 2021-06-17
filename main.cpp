#include <iomanip>
#include <iostream>
#include <string>
#include "db.hpp"
#include "student.hpp"

void testsearchSurname(Db& test1) {
    std::cout<<"test searchSurname "<<'\n';
    int nr_test = 0;
    std::string surname2;

    std::cout << "enter the number of tests: ";
    std::cin >> nr_test;

    for (int i = 0; i < nr_test; i++) {
        std::cout << "enter the surname: ";
        std::cin >> surname2;

        test1.searchSurname(surname2);
    }
}

void testSearchPesel(Db& test2) {
     std::cout<<"test searchPesel "<<'\n';
    int nr_test = 0;
    size_t pesel2 = 0;

    std::cout << "enter the number of tests: ";
    std::cin >> nr_test;

    for (int i = 0; i < nr_test; i++) {
        std::cout << "enter the pesel: ";
        std::cin >> pesel2;

        test2.searchPesel(pesel2);
    }
}

int main() {
    std::vector<Student> test;

    test.push_back(Student("Jan", "Nowak", "Poznan", 4532, 90051401458, "M"));
    test.push_back(Student("Adam", "Konieczny", "Warszawa", 3456, 88051401458, "M"));
    test.push_back(Student("Piotr", "Nowak", "Poznan", 2879, 96051401458, "M"));
    test.push_back(Student("Anna", "Kowalska", "Poznan", 1245, 98051401458, "F"));
    test.push_back(Student("John", "Smith", "NewYork", 4531, 86051401458, "M"));
    test.push_back(Student("Łukasz", "Konieczny", "Bydgoszcz", 4539, 91051401458, "M"));
    test.push_back(Student("Krzysztof", "Stanowski", "Gdańsk", 4739, 78051401458, "M"));

    Db bd2(test);
    /*
    Db bd2;
    std::string test;
    while (std::cin >> test) {
        if (test == ":wq") {
            break;
        }

        if (bd2.addStudent()) {
            std::cout << "Student added.\n";
        } else {
            std::cout << "Student not added.\n";
        }
    }

    std::cout << "No. of student in Daabase: " << bd2.getDbSize() << '\n';
    */

     
    testsearchSurname(bd2);
    testSearchPesel(bd2);

    return 0;
}
