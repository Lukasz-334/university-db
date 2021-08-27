#pragma once
#include "Person.hpp"
class Employee : public Person {

    public:
    Employee(const std::string name,
             const std::string surname,
             const std::string address,
             const std::string pesel,
             const ID gender,  //enum
             size_t earnings);

    void setEarnings(const size_t& );
    size_t getEarnings() const;

private:
    size_t earnings_;
};