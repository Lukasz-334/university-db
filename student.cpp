#include "student.hpp"
#include "db.hpp"

Student::Student() {
}

Student::Student(std::string name, std::string surname, std::string address, std::string index, std::string pesel, std::string gender)
    : name_(name), surname_(surname), address_(address), index_(index), pesel_(pesel), gender_(gender) {
}

void Student::setName(const std::string& name) {
    name_ = name;
}
void Student::setSurname(const std::string& surname) {
    surname_ = surname;
}
void Student::setAddress(const std::string& address) {
    address_ = address;
}
void Student::setIndex(const std::string& index) {
    index_ = index;
}
void Student::setPesel(const std::string& pesel) {
    pesel_ = pesel;
}
void Student::setGender(const std::string& gender) {
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
std::string Student::getIndex() const {
    return index_;
}
std::string Student::getPesel() const {
    return pesel_;
}
std::string Student::getGender() const {
    return gender_;
}

void Student::printPersonality() {
    std::cout << "--------------------\n"
                 "Name: " + name_ + "\n"
                 "Surname: " + surname_ + "\n"
                 "Address: " + address_ + "\n"
                 "Index: " + index_ + "\n"
                 "PESEL: " + pesel_+ "\n"
                 "Gender: " + pesel_+ "\n";
}