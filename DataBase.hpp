#pragma once
#include <memory>
#include <vector>
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

class DataBase {
private:
    using dataVector = std::vector<std::unique_ptr<Person>>;

public:
    dataVector db_ = {};
    explicit DataBase() = default;
    DataBase(size_t size);
    void changeToSmall(std::string&);
    size_t stringToDouble(const std::string&);
    bool testPesel(const std::string&);
    bool checkPesel(size_t);

    bool searchPesel(const std::string&);
    std::vector<Person*> searchSurname(const std::string&);

    bool addEmployee(const Employee&);
    bool addStudent(const Student&);
    bool deleteStudent(const std::string&);

    void sortByEarnings();
    void sortByPesel();
    void sortBySurname();

    bool modificationOfEarnings(const std::string&, const size_t&);
    void printDb();
    void saveDataBaseToFile(const std::string&);
    void loadDataBaseFromFile(const std::string&, DataBase&);
    void dataGeneration();
    
    Student generatingStudentData();
    Employee GeneratingEmployeeData();
    size_t generatingANumber(size_t); 
    std::string generatingAMaleName();
    std::string generatingAFemaleName();

    std::string generatingAMaleSurname();
    std::string generatingAFemaleSurname();

    std::string generatingAPeselMale();
    std::string generatingAPeselFemale();

    std::string generatingAddress();
    std::string generatingIndex();
    size_t generatingEarnings();
};

