#include <memory>
#include <string>
#include <vector>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase uniDb;

    std::cout << "Generating data for the database " << std::endl;

    for (int i = 0; i < 5; i++) {
        Student st = uniDb.generatingStudentData();
        uniDb.addStudent(st);
    }

    for (int i = 0; i < 5; i++) {
        Employee emp = uniDb.GeneratingEmployeeData();
        uniDb.addEmployee(emp);
    }

    std::cout << "Saving data to the database" << std::endl;

    uniDb.saveDataBaseToFile("base.txt");

    std::cout << "Printout of data from the database " << std::endl;

    uniDb.printDb();

    return 0;
}
