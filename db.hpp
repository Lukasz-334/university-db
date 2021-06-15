#pragma once
#include "student.hpp"
#include <string>
#include <vector>

// Wyświetlanie całej bazy danych zrobie w interfejsie

class Db {
public:
    
    std::vector<Student> db_;

public:
    Db(void);
    Db(const Student& person);
    bool addStudent();  //powinna korzystać z funkcji do walidacji pesel
    Student search(const std::string& surname);
    Student search(size_t pesel);
    void sort(const std::string& surname);
    void sort(size_t pesel);
    void del(unsigned int index);
};
