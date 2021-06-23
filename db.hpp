#pragma once
#include <string>
#include <vector>
#include "student.hpp"
#include <fstream>
#include <cctype>
class Db {
private:
/* Private variables */
    std::vector<Student> db_;

public:
/* Costructor */

/* Setters */

/* Getters */
    size_t getDbSize() const;

/* Public functions */
    bool checkPesel(size_t);
    void addStudent();
    void addStudent(Student&);
    bool searchSurname(const std::string&);
    void searchSurnameInMenu();
    void searchPeselInMenu();
    bool searchPesel(const std::string&);
    void sortSurname();
    void changeToSmall(std::string&); 
    void sortPesel();
    void deleteStud(const std::string&);
    void deleteStudInMenu();
    void printDb();
    void saveDbToFile(const std::string&);
    void loadDbFromFile(const std::string&);
};
