#include "Person.hpp"
#include <string>

Person::Person(const std::string name,
               const std::string surname,
               const std::string address,
               const std::string pesel,
               const ID gender)  //enum
    : name_(name), surname_(surname), address_(address), pesel_(pesel), gender_(gender) {}

void Person::setName(std::string& name) {
    name_ = name;
}

void Person::setSurname(std::string& surname) {
    surname_ = surname;
}

void Person::setAddress(std::string& address) {
    address_ = address;
}

void Person::setPesel(std::string& pesel) {
    pesel_ = pesel;
}

void Person::setGender(ID& gender) {
    gender_ = gender;
}

std::string Person::getName() const {
    return name_;
}

std::string Person::getSurname() const {
    return surname_;
}

std::string Person::getAddress() const {
    return address_;
}

std::string Person::getPesel() const {
    return pesel_;
}

ID Person::getGender() const {
    return gender_;
}
