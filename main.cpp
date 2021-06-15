#include <iomanip>
#include <iostream>
#include <string>
#include "db.hpp"
#include "student.hpp"

int main() {
    Student student1("Jan", "Nowak", "Poznan", 4532, 44051401458, 'M');

    Db dataBase(student1);
    
    bool score;
    score = dataBase.checkPesel(student1.getPesel());
    std::cout << std::boolalpha << score << '\n';
}
