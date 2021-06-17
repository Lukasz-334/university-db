#include "db.hpp"
#include "student.hpp"
#include <iostream>

Db::Db(){};

Db::Db(const Student& person) {
    db_.push_back(person);
}

Db::Db(std::vector<Student>& db) {
    for (auto st : db) {
        db_.push_back(st);
    }
}

size_t Db::getDbSize() const {
    return db_.size();
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

bool Db::addStudent() {
    bool echo = true;
    Student tmp_stud;
    std::string tmp_str;  //tymczasowy string
    size_t tmp_int;       //tymczasowy unsint
    size_t tmp_size;      // to zmienne na chwile
    std::cout << "\n Name: ";
    std::cin >> tmp_str;
    if (echo) {
        std::cout << tmp_str << '\n';
    }
    tmp_stud.setName(tmp_str);
    std::cout << " Surname: ";
    std::cin >> tmp_str;
    if (echo) {
        std::cout << tmp_str << '\n';
    }
    tmp_stud.setSurname(tmp_str);
    std::cout << " Address: ";
    std::cin >> tmp_str;
    if (echo) {
        std::cout << tmp_str << '\n';
    }
    tmp_stud.setAddress(tmp_str);
    std::cout << " Index: ";
    std::cin >> tmp_int;
    if (echo) {
        std::cout << tmp_int << '\n';
    }
    tmp_stud.setIndex(tmp_int);
    std::cout << " Gender: ";
    std::cin >> tmp_str;
    if (echo) {
        std::cout << tmp_str << '\n';
    }
    tmp_stud.setGender(tmp_str);
    std::cout << " PESEL: ";
    std::cin >> tmp_size;
    if (echo) {
        std::cout << tmp_size << '\n';
    }

    if (checkPesel(tmp_size)) {
        tmp_stud.setPesel(tmp_size);
        db_.emplace_back(tmp_stud);
        return true;
    } else {
        std::cout << "\n Wrong PESEL !\n";
        return false;
    }
}

void Db::searchSurname(const std::string& surname) {
    bool studNotFound = true;
    std::cout << "Searching by surname: " <<surname<<std::endl;
    for (auto person1 : Db::db_) {
        if (person1.getSurname() == surname) {
            //person1.personalData();
            studNotFound = false;
        }
    }
    if (studNotFound) {
        std::cout << "Not found.\n";
    }
}

void Db::searchPesel(const size_t pesel) {
    bool peselNotFound = true;
    std::cout << "Searching by pesel: " << pesel << '\n';

    for (auto person1 : Db::db_) {
        if (person1.getPesel() == pesel) {
            //person1.personalData();
            peselNotFound = false;
            break;
        }
    }
    if (peselNotFound) {
        std::cout << "Not found.\n";
    }
}

int Db::searchIndex(const size_t index2) {
    int nr_index = -1;

    for (int i = 0; i < Db::db_.size(); i++) {
        if (db_[i].getIndex() == index2) {
            nr_index = i;
            return nr_index;
        }
    }

    return nr_index;
}
/*
void Db::sortSurname() {
    std::sort(db_.begin(), db_.end());
}
*/
// void Db::sort(size_t pesel) {
// }
// void Db::del(size_t index) {
// }
