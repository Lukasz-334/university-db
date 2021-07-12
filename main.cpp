#include <memory>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include <string>
#include "Student.hpp"
#include <vector>

int main() {
    
  DataBase uniDb;
  std::cout << uniDb.db_.size(); 
  std::cout << '\n';
  Student stud1("Adam","Konieczny","Warszawa","01241249667",ID::StudentMale,"31456");
  uniDb.addPerson(stud1);
  std::cout << uniDb.db_.size();
  std::cout << '\n';
  Employee emp("Ala","Lala","Warszawa","47052253642",ID::StudentFemale ,1245);
  uniDb.addPerson(emp);
  std::cout << uniDb.db_.size();
  std::cout << '\n';
  
  
  
  return 0;
}
