#include "Employee.hpp"
#include "DataBase.hpp"
#include "Person.hpp"

Employee::Employee(const std::string name,
                   const std::string surname,
                   const std::string address,
                   const std::string pesel,
                   const ID gender,  //enum
                   size_t earnings)
    : Person(name, surname, address, pesel, gender), earnings_(earnings){};

void Employee::setEarnings(const size_t& earnings) {
    earnings_ = earnings;
}
size_t Employee::getEarnings() const {
    return earnings_;
}
