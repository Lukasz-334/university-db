#include "db.hpp"
#include <iostream> 
#include <string>
#include "student.hpp"

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

void Db::addStudent() {
    Student tmp_stud;
    std::string tmp_str;  //tymczasowy string
    size_t tmp_size;      // to zmienne na chwile
    std::cout << "\n Name: ";
    std::cin >> tmp_str;
    tmp_stud.setName(tmp_str);
    std::cout << " Surname: ";
    std::cin >> tmp_str;
    tmp_stud.setSurname(tmp_str);
    std::cout << " Address: ";
    std::cin >> tmp_str;
    tmp_stud.setAddress(tmp_str);
    std::cout << " Index: ";
    std::cin >> tmp_str;
    tmp_stud.setIndex(tmp_str);
    std::cout << " Gender: ";
    std::cin >> tmp_str;
    tmp_stud.setGender(tmp_str);
    std::cout << " PESEL: ";
    std::cin >> tmp_str;
    if (searchPesel(tmp_str)) {
        try {
            tmp_size = std::stod(tmp_str);
        } catch (...) {
            tmp_size = 0;
        }
        if (checkPesel(tmp_size)) {
            tmp_stud.setPesel(tmp_str);
            db_.emplace_back(tmp_stud);
            std::cout << "Student added.\n";
            std::cout << "Number of student in Database: " << getDbSize() << '\n';
        } else {
            std::cout << "\n Student not added. Wrong PESEL !\n";
        }
    } else {
            std::cout << "\n Student with this PESEL already exists!\n";
    }
}

// void Db::sort(const std::string& surname) {
// }
// void Db::sort(size_t pesel) {
// }
// void Db::del(size_t index) {
// }
void Db::printDb() {
    if (db_.size() > 0) {
        for (auto& person1 : db_) {
            person1.printPersonality();
        }
    } else {
        std::cout << "No records in database.\n";
    }
}
void Db::searchSurname(const std::string& surname) {
    bool studNotFound = true;
    std::cout << "Searching by surname: " << surname << std::endl;

    for (auto person1 : db_) {
        if (person1.getSurname() == surname) {
            person1.printPersonality();
            studNotFound = false;
        }
    }
    if (studNotFound) {
        std::cout << "Not found.\n";
    }
}
void Db::searchSurnameInMenu() {
    std::string tmp_str;
    std::cout << "Please enter surname: ";
    std::cin >> tmp_str;
    searchSurname(tmp_str);
}

bool Db::searchPesel(const std::string& pesel) {
    bool peselNotFound = true;
    std::cout << "Searching by pesel: " << pesel << '\n';
    for (auto person1 : db_) {
        if (person1.getPesel() == pesel) {
            person1.printPersonality();
            peselNotFound = false;
            break;
        }
    }
    if (peselNotFound) {
        std::cout << "Not found.\n";
    }
    return peselNotFound;
}
void Db::searchPeselInMenu() {
    std::string tmp_str;
    size_t tmp_size;
    std::cout << "Please enter PESEL: ";
    std::cin >> tmp_str;
    searchPesel(tmp_str);
}

// int Db::searchIndex(const size_t index2) {
//     int nr_index = -1;

//     for (int i = 0; i < Db::db_.size(); i++) {
//         if (db_[i].getIndex() == index2) {
//             nr_index = i;
//             return nr_index;
//         }
//     }

//     return nr_index;
 

void Db::sortSurname() 
{
    std::sort(db_.begin(), db_.end());
}

