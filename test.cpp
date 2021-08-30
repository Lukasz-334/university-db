#include "DataBase.hpp"
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

#include <string>
#include <vector>
#include "gtest/gtest.h"

DataBase uniDb;

TEST(checkPeselTest, checksIfThePeselIsCorrect) {
    std::vector<std::string> tested_pesel = {
        "01241249667",
        "47052253642",
        "980102337145",
        "98010233714",
        "0124124344",
    };

    std::vector<size_t> tested_pesel_int;
    for (const std::string& s : tested_pesel) {
        tested_pesel_int.push_back(uniDb.stringToDouble(s));
    }
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(0)), true);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(1)), true);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(2)), false);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(3)), true);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(4)), false);
}

TEST(changeToSmallTest, changeUppercaseToLowercase) {
    std::string test_string = "FRUIT";
    std::string test_string_first = "abcde";
    std::string test_string_second = "AbCdEf";

    uniDb.changeToSmall(test_string);
    ASSERT_EQ(test_string, "fruit");

    uniDb.changeToSmall(test_string_first);
    ASSERT_EQ(test_string_first, "abcde");

    uniDb.changeToSmall(test_string_second);
    ASSERT_EQ(test_string_second, "abcdef");
}
//bool addEmployee(const Employee&);

TEST(addEmployeeTest, testOfAddingAPersonToTheDatabase) {
    Employee emp("Adam", "Konieczny", "Warszawa", "01241249667", ID::EmployeeMale, 5678);
    Employee emp1("Ala", "Bala", "Warszawa", "47052253642", ID::EmployeeFemale, 1245);
    Employee emp2("Piotr", "Konieczny", "Warszawa", "98010233714", ID::EmployeeMale, 3452);
    Employee emp3("Ryszard", "Konieczny", "Toruń", "98010233714", ID::EmployeeMale, 3453);
    Employee emp4("Zbigniew", "Nowak", "Toruń", "111111111", ID::EmployeeMale, 3753);

    ASSERT_EQ(uniDb.addEmployee(emp), true);
    ASSERT_EQ(uniDb.addEmployee(emp1), true);
    ASSERT_EQ(uniDb.addEmployee(emp2), true);
    ASSERT_EQ(uniDb.addEmployee(emp3), false);
    ASSERT_EQ(uniDb.addEmployee(emp4), false);
}

//void deleteStudent(const std::string& index);

TEST(deleteStudentTest, testToRemoveAStudentFromTheBase) {
    uniDb.db_.clear();

    Student stud1("Ala", "Lala", "Warszawa", "47052253642", ID::StudentFemale, "5678");
    Student stud2("Adam", "Konieczny", "Warszawa", "01241249667", ID::StudentMale, "1234");
    Student stud3("Piotr", "Nowak", "Warszawa", "98010233714", ID::StudentMale, "9876");
    uniDb.addStudent(stud1);
    uniDb.addStudent(stud2);
    uniDb.addStudent(stud3);

    size_t base_size = uniDb.db_.size();
    uniDb.deleteStudent("5678");
    ASSERT_EQ(base_size, uniDb.db_.size()+1);

    base_size = uniDb.db_.size();
    uniDb.deleteStudent("2222");
    ASSERT_EQ(base_size, uniDb.db_.size());

}