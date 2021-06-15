#include <iostream>
#include <string>
#include <iomanip>
#include "db.hpp"
#include "student.hpp"


int main() {

    Student student1("Jan","Nowak","Poznan",4532,44051401458,'M');
    
    Db bd2(student1);
    bool score;
    

    score = bd2.db_[0].checkPesel(student1.getPesel());
    
    
    std::cout<<std::boolalpha<<score<<'\n';
    
   
    
    //std::cout << "student 1 gender: " << student1.getPesel() << '\n';
}
