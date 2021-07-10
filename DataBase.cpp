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
    bool peselFound = false;
    for (int i=0;i<db_.size();i++) {
        if (db_[i]->getPesel() == pesel) {
            peselFound = true;
            break;
        }
    }
    return peselFound;
}
