#include <memory>
#include <string>
#include <vector>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase uniDb;

    Student stud1("Ala", "Cccd", "Warszawa", "47052253642", ID::Female, "5678");
    Student stud2("Adam", "ZZZZrtyewerg", "Warszawa", "01241249667", ID::Male, "1234");
    Employee emp1("Jan", "aBBB", "Sochaczew", "02322962488", ID::Male, 5678);
    Student stud3("Piotr", "bacB", "Warszawa", "98010233714", ID::Male, "9876");
    Employee emp2("Piotr", "aBCB", "Sochaczew", "79051074234", ID::Male, 2623);
    Employee emp3("John", "Dada", "NewYork", "83091644917", ID::Male, 3467);
    Employee emp4("Jacek", "CcCC", "NewYork", "03282974346", ID::Male, 1467);
    Employee emp5("Helena", "Aabb", "Opole", "91031583965", ID::Male, 3322);
    Student stud4("Krzysztof", "baba", "Torun", "03222576535", ID::Male, "2869");
    Employee emp6("Teodora", "Dbda", "Kamion", "03310167447", ID::Male, 10731);
    uniDb.addStudent(stud2);
    uniDb.addStudent(stud3);
    uniDb.addEmployee(emp5);
    uniDb.addEmployee(emp6);
    uniDb.addStudent(stud4);
    uniDb.addEmployee(emp1);
    uniDb.addEmployee(emp2);
    uniDb.addStudent(stud1);
    uniDb.addEmployee(emp3);
    uniDb.addEmployee(emp4);
    uniDb.saveDbToFile("base.txt");

    std::cout << "number in the database " << uniDb.db_.size();
    std::cout << '\n';
    uniDb.printDb();
    uniDb.sortByEarnings();
    uniDb.printDb();
    uniDb.sortBySurname();
    uniDb.printDb();
    uniDb.sortByPesel();
    uniDb.printDb();

    return 0;
}
