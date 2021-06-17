#include "db.hpp"
#include <iostream>
#include <string>
#include "student.hpp"

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
    std::string tmp_str;   //tymczasowy string
    unsigned int tmp_int;  //tymczasowy unsint
    size_t tmp_size;       // to zmienne na chwile
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
    std::vector<Student> Vecsurname;

    for (auto person1 : Db::db_) {
        if (person1.getSurname() == surname) {
            Vecsurname.push_back(person1);
        }
    }
    if (Vecsurname.empty()) {
        std::cout << "There is no such student in the database.\n";
    } else if (Vecsurname.size() == 1) {
        std::cout << "There is 1 student in the database:\n";
        std::cout << Vecsurname[0].getSurname() << ' ';
        std::cout << Vecsurname[0].getName() << std::endl;

    } else {
        std::cout << "There are " << Vecsurname.size() << " students in the database:\n";
        for (auto person2 : Vecsurname) {
            std::cout << person2.getSurname() << ' ';
            std::cout << person2.getName() << std::endl;
        }
    }
}

void Db::searchPesel(const size_t pesel) {
    bool test = true;
    size_t Pesel_found = 1;
    int nr_student = 0;

    for (int i = 0; i < Db::db_.size(); i++) {
        if (db_[i].getPesel() == pesel) {
            test = false;
            nr_student = i;
            break;
        }
    }
    if (test) {
        std::cout << "no pesel in the database " << '\n';
    } else {
        std::cout << db_[nr_student].getSurname() << ' '
                  << db_[nr_student].getName() << ' '
                  << db_[nr_student].getPesel() << '\n';
    }
}

// void Db::sort(const std::string& surname) {
// }
// void Db::sort(size_t pesel) {
// }
// void Db::del(unsigned int index) {
// }
