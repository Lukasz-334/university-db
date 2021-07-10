#include <memory>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase base(5);

    base.addPerson();
    std::cout<<std::endl;
    std::cout<<base.db_[0]->getName();
    
    return 0;
}
