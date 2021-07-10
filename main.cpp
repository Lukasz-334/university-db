#include <memory>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    
  
    DataBase base(5);
    
    std::unique_ptr<Person> ptr= std::make_unique<Person>();
    std::unique_ptr<Person> ptr2= std::make_unique<Person>();
    
    ptr->setName("piotr");
    ptr->setPesel("44051401458");

    ptr2->setPesel("2");

    base.addPerson(ptr);
    base.addPerson(ptr2);


    return 0;
}
