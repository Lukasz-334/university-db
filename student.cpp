#include "student.hpp"
#include "db.hpp"

Student::Student() {
}

Student::Student(std::string name, std::string surname, std::string address, size_t index, size_t pesel, std::string gender)
    : name_(name), surname_(surname), address_(address), index_(index), pesel_(pesel), gender_(gender) {
}

bool Student::operator<(const Student& a)
{

return a.getSurname()<surname_;

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
void Student::setIndex(size_t index) {
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
size_t Student::getIndex() const {
    return index_;
}
size_t Student::getPesel() const {
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
                 "Index: " + std::to_string(index_) + "\n"
                 "PESEL: " + std::to_string(pesel_)+ "\n"
                 "Gender: " + std::to_string(pesel_)+ "\n";
}