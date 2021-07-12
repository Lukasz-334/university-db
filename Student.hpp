#pragma once
#include "Person.hpp"
class Student : public Person {
public:
    Student(const std::string name,
            const std::string surname,
            const std::string address,
            const std::string pesel,
            const ID gender,  //enum
            const std::string index);

    void setIndex(std::string&);
    std::string getIndex() const;

private:
    std::string index_;
};
