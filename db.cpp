#include "db.hpp"
#include <iostream>
#include <string>
#include "student.hpp"

Db::Db(const Student& p) {
    db_.push_back(p);
}

bool Db::checkPesel(size_t pesel) {
    int multiplication[11] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int sum = 0;
    int tab_pesel[11]{};
    for (int i = 10; i >= 0; i--) {
        tab_pesel[i] = pesel % 10;
        pesel = pesel / 10;
    }
    for (int i = 0; i < 11; i++) {
        sum = tab_pesel[i] * multiplication[i] + sum;
    }
    return ((sum > 0) && (sum % 10 == 0));
}

// Student::Student(std::string name, std::string surname, std::string address, unsigned int index, size_t pesel, char gender)

bool Db::addStudent() {
    Student tmp_stud;
    std::string tmp_str;   //tymczasowy string
    unsigned int tmp_int;  //tymczasowy unsint
    size_t tmp_size;       // to zmienne na chwile
    char tmp_char;         //potrzebne wszystkich typow
    std::cout << "\n Name: ";
    std::cin >> tmp_str;
    tmp_stud.setName(tmp_str);
    std::cout << "\n Surname: ";
    std::cin >> tmp_str;
    tmp_stud.setSurname(tmp_str);
    std::cout << "\n Address: ";
    std::cin >> tmp_str;
    tmp_stud.setAddress(tmp_str);
    std::cout << "\n Index: ";
    std::cin >> tmp_int;
    tmp_stud.setIndex(tmp_int);
    std::cout << "\n Gender: ";
    std::cin >> tmp_char;
    tmp_stud.setGender(tmp_char);
    std::cout << "\n PESEL: ";
    std::cin >> tmp_size;
    if (checkPesel(tmp_size)) {
        tmp_stud.setPesel(tmp_size);
        db_.emplace_back(tmp_stud);
        return true;
    } else {
        std::cout << "\n Wrong PESEL !  ";
        return false;
    }
}

// Student Db::search(const std::string& surname) {
// }
// Student Db::search(size_t pesel) {
// }
// void Db::sort(const std::string& surname) {
// }
// void Db::sort(size_t pesel) {
// }
// void Db::del(unsigned int index) {
// }
