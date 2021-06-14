#include "bd.hpp"
#include <string>
#include <iostream>

class Student {
 private:
    std::string name_;
    std::string surname_;
    std::string address_;
    int index_;
    int pesel_;
    char gender_; //Not Specified Male Female Non-Binary

 public:

    void setName(const std::string& name) { name_ = name; }
    void setSurname(const std::string& surname) { surname_ = surname; }
    void setAddress(const std::string& address) { address_ = address; }
    void setIndex(int index) { index_ = index; }
    void setPesel(int pesel) { pesel_ = pesel; }
    void setGender(char gender) { gender_ = gender; }


    std::string getName() const    { return name_; }
    std::string getSurname() const { return surname_; }
    std::string getAddress() const { return address_; }
    int getIndex() const           { return index_; }
    int getPesel() const           { return pesel_; }
    char getGender() const         { return gender_; }  



};

