#include "db.hpp"
#include "student.hpp"
#include <iostream>
#include <string>

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
     std::string tmp_str; //tymczasowy string
     size_t tmp_int; //tymczasowy numer
     std::cout << "\n Name: ";
     std::cin >> tmp_str;
     tmp_stud.setName(tmp_str);
     
     return true;
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
