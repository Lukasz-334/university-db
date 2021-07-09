#pragma once
#include <memory>
#include "Person.hpp"
#include <vector>

class DataBase {
public:
using dataVector = std::vector<std::unique_ptr<Person>>;

private:
dataVector db_= {};


};