#include <iostream>
#include <string>
#include "bd.hpp"
#include 

int main() {
    Student student1;
    student1.setName("Jan");
    std::cout << "student 1 name: " << student1.getName() << '\n';
}
