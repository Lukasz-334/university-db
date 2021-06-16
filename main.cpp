#include <iomanip>
#include <iostream>
#include <string>
#include "db.hpp"
#include "student.hpp"

void testcheckSurname(Db test1) {
    test1.searchSurname("Konieczny");
    test1.searchSurname("Smith");
    test1.searchSurname("noName");
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

    testcheckSurname(bd2);

    return 0;
}
