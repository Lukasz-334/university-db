#include "student.hpp"
#include "db.hpp"

Student::Student(std::string name, std::string surname, std::string address, unsigned int index, size_t pesel, std::string gender)
    : name_(name), surname_(surname), address_(address), index_(index), pesel_(pesel), gender_(gender) {}

void Student::setName(const std::string& name) {
    name_ = name;
}
void Student::setSurname(const std::string& surname) {
    surname_ = surname;
}
void Student::setAddress(const std::string& address) {
    address_ = address;
}
void Student::setIndex(unsigned int index) {
    index_ = index;
}
void Student::setPesel(size_t pesel) {
    pesel_ = pesel;
}
void Student::setGender(std::string gender) {
    gender_ = gender;
}

std::string Student::getName() const {
    return name_;
}
std::string Student::getSurname() const {
    return surname_;
}
std::string Student::getAddress() const {
    return address_;
}
unsigned int Student::getIndex() const {
    return index_;
}
size_t Student::getPesel() const {
    return pesel_;
}
std::string Student::getGender() const {
    return gender_;
}