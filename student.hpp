#pragma once

#include <iostream>
#include <string>
#include <algorithm>
class Student {
private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string index_;
    std::string pesel_;
    std::string gender_;  //Not Specified Male Female Non-Binary

public:
    Student();
    Student(std::string, std::string, std::string, std::string, std::string, std::string);
    
    void setName(const std::string&);
    void setSurname(const std::string&);
    void setAddress(const std::string&);
    void setIndex(const std::string&);
    void setPesel(const std::string&);
    void setGender(const std::string&);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getIndex() const;
    std::string getPesel() const;
    std::string getGender() const;
    void printPersonality();
    bool operator<(const Student& student_a);
    //bool operator<(const Student& student_b);
};
