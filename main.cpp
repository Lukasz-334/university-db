#include <memory>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase base(5);
   
    base.db_.push_back(std::make_unique<Person>());
    base.db_[0]->setName("jjj");
    std::cout <<base.db_[0]->getName();

   

    return 0;
}
