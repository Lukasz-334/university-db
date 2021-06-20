#pragma once
#include <string>
#include <vector>
#include "student.hpp"
class Db {
public:
    std::vector<Student> db_;
    
public:
    bool checkPesel(size_t);
    void addStudent();
    void searchSurname(const std::string&);
    void searchSurnameInMenu();
    void searchPeselInMenu();
    bool searchPesel(const std::string&);
    void deleteStud(const std::string&);
    void deleteStudInMenu();
    void sortSurname();
    void sortPesel();
    void printDb();

    size_t getDbSize() const;

    
};
