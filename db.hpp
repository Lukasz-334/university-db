#pragma once
#include <string>
#include <vector>
#include "student.hpp"

// Wyświetlanie całej bazy danych zrobie w interfejsie

class Db {
public:
    std::vector<Student> db_;

public:
    Db();
    Db(const Student& person);
    Db(std::vector<Student>& db);
    bool checkPesel(size_t);
    bool addStudent();  //powinna korzystać z funkcji do walidacji pesel
    void searchSurname(const std::string& surname);
    void searchPesel(const size_t pesel);
    void sort(const std::string&);
    void sort(size_t);
    void del(unsigned int);

    size_t getDbSize() const;
};
