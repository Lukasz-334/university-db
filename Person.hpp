#pragma once
#include <iostream>
#include <string>

enum class ID : const char {
    StudentMale = 'M',
    StudentFemale = 'F',
    StudentOther = 'O',
    EmployeeMale = 'M',
    EmployeeFemale = 'F',
    EmployeeOther = 'O'
};

class Person {
public:
    explicit Person() = default;
    Person(const std::string name,
           const std::string surname,
           const std::string address,
           const std::string pesel,
           const ID gender);  //enum

    virtual ~Person() = default;

    virtual void setName(std::string&);
    virtual void setSurname(std::string&);
    virtual void setAddress(std::string&);
    virtual void setPesel(std::string&);
    virtual void setGender(ID&);

    virtual std::string getName() const;
    virtual std::string getSurname() const;
    virtual std::string getAddress() const;
    virtual std::string getPesel() const;
    virtual ID getGender() const;

private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string pesel_;
    ID gender_;
};