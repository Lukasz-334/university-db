#include <memory>
#include <string>
#include <vector>
#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

int main() {
    DataBase uniDb;

    for (int i = 0; i < 5; i++) {
        Student st = uniDb.generatingStudentData();
        uniDb.addStudent(st);
    }

    for (int i = 0; i < 5; i++) {
        Employee emp = uniDb.GeneratingEmployeeData();
        uniDb.addEmployee(emp);
    }
    uniDb.printDb();

    uniDb.saveDataBaseToFile("base.txt");

    //uniDb.loadDataBaseFromFile("base.txt", uniDb);

    //uniDb.printDb();

    return 0;
}
