#include <memory>
#include <string>
#include <vector>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase uniDb;

    
    Student stud1("Adam", "Konieczny", "Warszawa", "01241249667", ID::StudentMale, "31456");
    Employee emp1("Ala", "Lala", "Warszawa", "47052253642", ID::StudentFemale, 1245);
    Employee emp2("Piotr", "Nowak", "Warszawa", "98010233714", ID::StudentFemale, 345);
    
    uniDb.addStudent(stud1);
    uniDb.addEmployee(emp1);
    uniDb.addEmployee(emp2);

    std::cout <<"number in the database "<< uniDb.db_.size();
    std::cout << '\n';

    uniDb.sortByEarnings();
   
    for (const auto& pers : uniDb.db_) {
        if(pers->getEarnings() != 0){
        std::cout << pers->getEarnings();
        std::cout << '\n';
        }
    }

    return 0;
}
