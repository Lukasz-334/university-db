#pragma once
#include <memory>
#include <vector>
#include "Person.hpp"

class DataBase {
private:
    using dataVector = std::vector<std::unique_ptr<Person>>;
    
public:
    dataVector db_ = {};
    DataBase(size_t size);
    bool checkPesel(size_t);


};