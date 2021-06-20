#pragma once
#include <string>
#include <vector>
#include "student.hpp"
#include <fstream>

class Db {
public:
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
    void searchSurname(const std::string&);
    void searchSurnameInMenu();
    void searchPeselInMenu();
    bool searchPesel(const std::string&);
    // void sort(const std::string&);
    // void sort(const std::string&);
    void deleteStud(std::string index);
    void deleteStudInMenu();
    void printDb();
    void saveDbToFile(const std::string&);
    void loadDbFromFile(const std::string&);
};
