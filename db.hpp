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
    // void sort(const std::string&);
    // void sort(const std::string&);
    void deleteStud(std::string index);
    void deleteStudInMenu();
    void printDb();

    size_t getDbSize() const;
};
