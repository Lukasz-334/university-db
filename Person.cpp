#include "Person.hpp"

void Person::setName(const std::string& name) {
    name_ = name;
}

void Person::setSurname(const std::string& surname) {
    surname_ = surname;
}

void Person::setAddress(const std::string& address) {
    address_ = address;
}

void Person::setIndex(const std::string& index) {
    index_ = index;
}

void Person::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}

void Person::setGender(const std::string& gender) {
    gender_ = gender;
}
void Person::setEarnings(const size_t& earnings) {
    earnings_ = earnings;
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

std::string Person::getIndex() const {
    return index_;
}

std::string Person::getPesel() const {
    return pesel_;
}

std::string Person::getGender() const {
    return gender_;
}

size_t Person::getEarnings() const{
    return earnings_;
}