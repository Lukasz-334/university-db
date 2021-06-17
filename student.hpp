#pragma once

#include <iostream>
#include <string>

class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    size_t index_;
    size_t pesel_;
    std::string gender_;  //Not Specified Male Female Non-Binary

public:
    Student();
    Student(std::string, std::string, std::string, size_t, size_t, std::string);
    
    void setName(const std::string&);
    void setSurname(const std::string&);
    void setAddress(const std::string&);
    void setIndex(size_t);
    void setPesel(size_t);
    void setGender(std::string);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    size_t getIndex() const;
    size_t getPesel() const;
    std::string getGender() const;
    void printPersonality();
};
