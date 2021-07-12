#pragma once
#include <algorithm>
#include <memory>
#include <vector>
#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

class DataBase {
private:
    using dataVector = std::vector<std::unique_ptr<Person>>;

public:
    dataVector db_ = {};
    explicit DataBase() = default;
    DataBase(size_t size);
    bool checkPesel(size_t);
    bool searchPesel(const std::string&);
    bool addPerson(const Person&);
    bool testPesel(const std::string&);
    size_t stringToDouble(const std::string&);
    void sortByEarnings();
};