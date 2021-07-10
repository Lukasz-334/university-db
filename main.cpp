#include <memory>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase base(5);
   
    base.db_.push_back(std::make_unique<Person>());
    base.db_.push_back(std::make_unique<Person>());
    base.db_[0]->setPesel("888");
    base.db_[1]->setPesel("111");
    std::cout <<base.searchPesel("110");

   

    return 0;
}
