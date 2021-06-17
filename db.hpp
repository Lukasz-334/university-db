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
    void searchPesel(const size_t);
    void searchPeselInMenu();
    int searchIndex(const size_t);
    void sort(const std::string&);
    void sort(size_t);
    void del(size_t);
    void printDb();

    size_t getDbSize() const;
};
