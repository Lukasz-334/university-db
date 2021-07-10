#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "Person.hpp"

class DataBase {
private:
    using dataVector = std::vector<std::unique_ptr<Person>>;
    
public:
    dataVector db_ = {};
    DataBase(size_t size);
    bool checkPesel(size_t);
    bool searchPesel(const std::string& pesel);
    void addPerson();
    void addPerson(std::unique_ptr<Person>& ptr);
    bool testPesel(const std::string& );
    size_t stringToDouble(const std::string&);


};