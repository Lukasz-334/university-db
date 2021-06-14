#pragma once
#include <string>
#include <vector>
#include "student.hpp"

// Wyświetlanie całej bazy danych zrobie w interfejsie

class Db {
private:
    std::vector<Student> db_;
    bool checkPesel(size_t pesel);

public:
    bool addStudent(); //powinna korzystać z funkcji do walidacji pesel
    Student search(const std::string& surname);
    Student search(size_t pesel);
    void sort(const std::string& surname);
    void sort(size_t pesel);
    void del(unsigned int index);
};
