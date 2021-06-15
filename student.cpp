#include "student.hpp"
#include "db.hpp"

Student::Student(std::string name, std::string surname, std::string address, unsigned int index, size_t pesel, char gender)
: name_(name)
, surname_(surname)
, address_(address)
, index_(index)
, pesel_(pesel)
, gender_(gender)
{}

bool Student::checkPesel(size_t pesel) {
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
