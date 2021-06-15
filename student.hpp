#pragma once

#include <iostream>
#include <string>

class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    unsigned int index_;
    size_t pesel_;
    char gender_;  //Not Specified Male Female Non-Binary

public:
    Student(std::string name = "name", std::string surname = "surname", std::string address_ = "address", unsigned int index = 1234, size_t pesel = 12345678910, char gender = 'G');

    void setName(const std::string&);
    void setSurname(const std::string&);
    void setAddress(const std::string&);
    void setIndex(unsigned int);
    void setPesel(size_t);
    void setGender(char);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    unsigned int getIndex() const;
    size_t getPesel() const;
    char getGender() const;
};
