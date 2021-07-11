#include "DataBase.hpp"
#include <memory>
#include "Person.hpp"
#include <string>

DataBase::DataBase(size_t size = 0) {
    db_.reserve(size);
}

bool DataBase::checkPesel(size_t pesel) {
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

bool DataBase::searchPesel(const std::string& pesel) {
    bool peselFound = true;
    for (int i = 0; i < db_.size(); i++) {
        if (db_[i]->getPesel() == pesel) {
            peselFound = false;
            break;
        }
    }
    return peselFound;
}

bool DataBase::addPerson(Person& person){
    size_t tmp_size;
    try {
        tmp_size = std::stod(person.getPesel());
    } catch (...) {
        tmp_size = 0;
    }
    if (checkPesel(tmp_size)) {
        std::unique_ptr<Person> ptr = std::make_unique<Person>(person);
       db_.emplace_back(std::move(ptr));
    return true; 
    } return false;   
}

