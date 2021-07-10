#include "DataBase.hpp"
#include "Person.hpp"


DataBase::DataBase(size_t size=0){
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
    for (int i=0;i<db_.size();i++) {
        if (db_[i]->getPesel() == pesel) {
            peselFound = false;
            break;
        }
    }
    return peselFound;
}


void DataBase::addPerson() {
    std::unique_ptr<Person> ptr= std::make_unique<Person>();
    std::string tmp_str;
    size_t tmp_size;
    std::cout << "\n Name: ";
    std::getline(std::cin, tmp_str);
    ptr->setName(tmp_str);
    std::cout << " Surname: ";
    std::getline(std::cin, tmp_str);
    ptr->setSurname(tmp_str);
    std::cout << " Address: ";
    std::getline(std::cin, tmp_str);
    ptr->setAddress(tmp_str);
    std::cout << " Index: ";
    std::getline(std::cin, tmp_str);
    ptr->setIndex(tmp_str);
    std::cout << " Gender: ";
    std::getline(std::cin, tmp_str);
    ptr->setGender(tmp_str);
    std::cout << " PESEL: ";
    std::getline(std::cin, tmp_str);
    if (searchPesel(tmp_str)) {
        try {
            tmp_size = std::stod(tmp_str);
        } catch (...) {
            tmp_size = 0;
        }
        if (checkPesel(tmp_size)) {
            ptr->setPesel(tmp_str);
            db_.push_back(std::move(ptr));
            std::cout << "Student added.\n";
            std::cout << "Number of student in Database: " << db_.size() << '\n';
        } else {
            std::cout << "\n Student not added. Wrong PESEL !\n";
        }
    } else {
        std::cout << "\n Student with this PESEL already exists!\n";
    }
}
