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
  Student stud1("Adam","Konieczny","Warszawa","47052253642",ID::StudentMale,"31456");
  uniDb.addPerson(stud1);
  std::cout << uniDb.db_.size();
  std::cout << '\n';
  Student stud2("Ala","Lala","Warszawa","111",ID::StudentFemale ,"12345");
  uniDb.addPerson(stud2);
  std::cout << uniDb.db_.size();
  std::cout << '\n';
  return 0;
}
