#pragma once
#include <iostream>
#include <string>
class Person {
public:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string index_;
    std::string pesel_;
    std::string gender_;
    size_t earnings_;

    Person(void);
    virtual ~Person();

    void setName(const std::string&);
    void setSurname(const std::string&);
    void setAddress(const std::string&);
    void setIndex(const std::string&);
    void setPesel(const std::string&);
    void setGender(const std::string&);
    void setEarnings(const size_t&);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getIndex() const;
    std::string getPesel() const;
    std::string getGender() const;
    size_t getEarnings() const;
};
