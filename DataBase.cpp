#include "DataBase.hpp"
#include <memory>
#include <string>

DataBase::DataBase(size_t size = 0) {
    db_.reserve(size);
}

size_t DataBase::stringToDouble(const std::string& str) {
    size_t tmp = 1;
    if (str.size() != 11) {
        tmp = 2;
    } else {
        try {
            tmp = std::stod(str);
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

void DataBase::sortByEarnings(){

 std::sort(db_.begin(),db_.end(),[](std::unique_ptr<Person>& a, std::unique_ptr<Person>& b){
   
   size_t x = a->getEarnings();
   size_t y = b->getEarnings();

   return x<y;

 });

 }




