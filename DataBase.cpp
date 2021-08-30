#include "DataBase.hpp"
#include <algorithm>
#include <memory>
#include <string>

DataBase::DataBase(size_t size = 0) {
    db_.reserve(size);
}

void DataBase::changeToSmall(std::string& word) {
    std::transform(begin(word), end(word), begin(word), [](unsigned char c) {
        return std::tolower(c);
    });
}

size_t DataBase::stringToDouble(const std::string& str) {
    size_t tmp = 1;
    if (str.size() != 11) {
        tmp = 2;
    } else {
        try {
            tmp = static_cast<size_t>(std::stod(str));
        } catch (...) {
            tmp = 0;
        }
    }
    return tmp;
}

bool DataBase::testPesel(const std::string& tmp_str) {
    size_t tmp_size = 0;
    if (searchPesel(tmp_str)) {
        tmp_size = stringToDouble(tmp_str);
        if (checkPesel(tmp_size)) {
            std::cout << "Person added.\n";
            return true;
        } else {
            std::cout << "Wrong PESEL !\n";
            return false;
        }
    } else {
        std::cout << "Student with this PESEL already exists!\n";
        return false;
    }
}

bool DataBase::checkPesel(size_t pesel) {
    size_t multiplication[11] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    size_t sum = 0;
    size_t tab_pesel[11]{};
    for (int i = 10; i >= 0; i--) {
        tab_pesel[i] = pesel % 10;
        pesel = pesel / 10;
    }
    for (int i = 0; i < 11; i++) {
        sum = tab_pesel[i] * multiplication[i] + sum;
    }
    return ((sum > 0) && (sum % 10 == 0));
}

bool DataBase::searchPesel(const std::string& pesel) {
    bool peselFound = true;
    for (long unsigned int i = 0; i < db_.size(); i++) {
        if (db_[i]->getPesel() == pesel) {
            peselFound = false;
            break;
        }
    }
    return peselFound;
}

bool DataBase::addEmployee(const Employee& person) {
    std::string tmp_str_t = person.getPesel();
    if (testPesel(tmp_str_t)) {
        std::unique_ptr<Employee> ptr = std::make_unique<Employee>(person);

        db_.emplace_back(std::move(ptr));
        return true;
    }
    return false;
}
bool DataBase::addStudent(const Student& person) {
    std::string tmp_str_t = person.getPesel();
    if (testPesel(tmp_str_t)) {
        std::unique_ptr<Student> ptr = std::make_unique<Student>(person);

        db_.emplace_back(std::move(ptr));
        return true;
    }
    return false;
}

void DataBase::sortByEarnings() {
    std::sort(db_.begin(), db_.end(), [](std::unique_ptr<Person>& first, std::unique_ptr<Person>& second) {
        size_t first_person = first->getEarnings();
        size_t second_person = second->getEarnings();

        return first_person < second_person;
    });
}

void DataBase::sortByPesel() {
    std::sort(db_.begin(), db_.end(), [](const std::unique_ptr<Person>& first, const std::unique_ptr<Person>& second) {
        std::string first_pesel = first->getPesel();
        std::string second_pesel = second->getPesel();
        if ((first_pesel[0] == '0') || (first_pesel[0] == '1')) {
            first_pesel += 1;
        }
        if ((second_pesel[0] == '0') || (second_pesel[0] == '1')) {
            second_pesel += 1;
        }

        if (first_pesel.size() == second_pesel.size()) {
            return first_pesel < second_pesel;
        } else {
            return first_pesel.size() < second_pesel.size();
        }

        return first_pesel > second_pesel;
    });
}

void DataBase::sortBySurname() {
    std::sort(db_.begin(), db_.end(), [&](const std::unique_ptr<Person>& first, const std::unique_ptr<Person>& second) {
        std::string first_surname = first->getSurname();
        std::string second_surname = second->getSurname();
        changeToSmall(first_surname);
        changeToSmall(second_surname);
        return first_surname < second_surname;
    });
}

std::vector<Person*> DataBase::searchSurname(const std::string& surname) {
    std::vector<Person*> vecSurname;
    Person* ptr;
    std::string surnameA = surname;
    std::string surnameB;
    changeToSmall(surnameA);

    for (long unsigned int i = 0; i < db_.size(); i++) {
        surnameB = db_[i]->getSurname();
        changeToSmall(surnameB);
        if (surnameA == surnameB) {
            ptr = db_[i].get();
            vecSurname.push_back(ptr);
        }
    }
    return vecSurname;
}

void DataBase::modificationOfEarnings() {
    std::size_t amount;
    std::string pesel;
    bool peselFound = false;
    std::cout << "enter the employee's PESEL number: ";
    std::cin >> pesel;
    for (long unsigned int i = 0; i < db_.size(); i++) {
        if ((db_[i]->getPesel() == pesel)) {
            std::cout << "earnings to change: ";
            std::cin >> amount;
            db_[i]->setEarnings(amount);
            peselFound = true;
            break;
        }
    }
    if (peselFound == false) {
        std::cout << "Wrong PESEL !\n ";
    }
}

void DataBase::deleteStudent(const std::string& index) {
    auto index_position = std::find_if(std::begin(db_), std::end(db_), [index](const std::unique_ptr<Person>& p) {
        return (index == p->getIndex());
    });

    if (index_position != std::end(db_)) {
        db_.erase(index_position);
        std::cout << "Student removed" << '\n';
    } else {
        std::cout << "Index nr " << index << " not found" << '\n';
    }
}