#include "Student.hpp"
#include "DataBase.hpp"
#include "Person.hpp"

Student::Student(const std::string name,
                 const std::string surname,
                 const std::string address,
                 const std::string pesel,
                 const ID gender,  //enum
                 const std::string index)
    : Person(name, surname, address, pesel, gender), index_(index) {
}

void Student::setIndex(std::string& index) {
    index_ = index;
}

std::string Student::getIndex() const {
    return index_;
}