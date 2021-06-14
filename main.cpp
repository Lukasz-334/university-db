#include <iostream>
#include <string>
#include "bd.hpp"


int main() {
    Student student1("Jan","Nowak","Poznan",4532,92071645517,'M');
    
    std::cout << "student 1 name: " << student1.getName() << '\n';
    std::cout << "student 1 surname: " << student1.getSurname() << '\n';
    std::cout << "student 1 address: " << student1.getAddress() << '\n';
    std::cout << "student 1 gender: " << student1.getGender() << '\n';
}
