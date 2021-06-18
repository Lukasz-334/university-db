#pragma once
#include <string>
#include <vector>
#include "student.hpp"

// Wyświetlanie całej bazy danych zrobie w interfejsie

class Db {
public:
    std::vector<Student> db_;
    
public:
    bool checkPesel(size_t);
    void addStudent();
    void searchSurname(const std::string&);
    void searchSurnameInMenu();
    bool searchPesel(const std::string&);
    void searchPeselInMenu();

    void sortSurname();
   // void sortPesel();
    int searchIndex(const std::string&); 

    void del(const std::string&);
    void printDb();

    size_t getDbSize() const;
};
