#pragma once

#include <iostream>
#include <string>

class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    int index_;
    size_t pesel_;
    char gender_;  //Not Specified Male Female Non-Binary

public:
    Student(std::string name = "name", std::string surname = "surname", std::string address_ = "address", unsigned int index = 1234, size_t pesel = 12345678910, char gender = 'G');
    void setName(const std::string& name) { name_ = name; }
    void setSurname(const std::string& surname) { surname_ = surname; }
    void setAddress(const std::string& address) { address_ = address; }
    void setIndex(unsigned int index) { index_ = index; }
    void setPesel(size_t pesel) { pesel_ = pesel; }
    void setGender(char gender) { gender_ = gender; }

    std::string getName() const { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    int getIndex() const { return index_; }
    int getPesel() const { return pesel_; }
    char getGender() const { return gender_; }
};

