#include <string>
#include <vector>
#include "DataBase.hpp"
#include "gtest/gtest.h"

DataBase uniDb;

TEST(checkPeselTest, checksIfThePeselIsCorrect) {
    std::vector<std::string> tested_pesel = {
        "01241249667",
        "47052253642",
        "980102337145",
        "98010233714",
        "0124124344",
        "78051401458"};

    std::vector<size_t> tested_pesel_int;
    for (const std::string& s : tested_pesel) {
        tested_pesel_int.push_back(uniDb.stringToDouble(s));
    }
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(0)), true);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(1)), true);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(2)), false);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(3)), true);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(4)), false);
    EXPECT_EQ(uniDb.checkPesel(tested_pesel_int.at(5)), false);
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
    ASSERT_EQ(base_size, uniDb.db_.size() + 1);

    base_size = uniDb.db_.size();
    uniDb.deleteStudent("2222");
    ASSERT_EQ(base_size, uniDb.db_.size());
}

TEST(searchPeselTest, returnsFalseIfPeselExists) {
    uniDb.db_.clear();
    Student stud1("Ala", "Lala", "Warszawa", "47052253642", ID::StudentFemale, "5678");
    Student stud2("Adam", "Konieczny", "Warszawa", "01241249667", ID::StudentMale, "1234");
    Student stud3("Piotr", "Nowak", "Warszawa", "98010233714", ID::StudentMale, "9876");
    uniDb.addStudent(stud1);
    uniDb.addStudent(stud2);
    uniDb.addStudent(stud3);

    ASSERT_EQ(uniDb.searchPesel("47052253642"), false);
    ASSERT_EQ(uniDb.searchPesel("01241249667"), false);
    ASSERT_EQ(uniDb.searchPesel("01241249669"), true);
}

TEST(searchSurnameTest, returnsAVectorOfSurnames) {
    uniDb.db_.clear();
    Student stud1("Ala", "Lala", "Warszawa", "47052253642", ID::StudentFemale, "5678");
    Student stud2("Adam", "Konieczny", "Warszawa", "01241249667", ID::StudentMale, "1234");
    Student stud3("Piotr", "Konieczny", "Warszawa", "98010233714", ID::StudentMale, "9876");
    Employee emp("Jan", "Nowak", "Sochaczew", "02322962488", ID::EmployeeMale, 5678);

    uniDb.addStudent(stud1);
    uniDb.addStudent(stud2);
    uniDb.addStudent(stud3);
    uniDb.addEmployee(emp);

    std::vector<Person*> v_surname;
    v_surname = uniDb.searchSurname("Konieczny");

    ASSERT_EQ("Konieczny", v_surname.at(0)->getSurname());
    ASSERT_EQ("Konieczny", v_surname.at(1)->getSurname());
    ASSERT_EQ(2, v_surname.size());
}

TEST(sortByEarningsTest, SortsEarningsInAscendingOrder) {
    uniDb.db_.clear();
    Student stud1("Ala", "Lala", "Warszawa", "47052253642", ID::StudentFemale, "5678");
    Student stud2("Adam", "Konieczny", "Warszawa", "01241249667", ID::StudentMale, "1234");
    Employee emp1("Jan", "Nowak", "Sochaczew", "02322962488", ID::EmployeeMale, 5678);
    Student stud3("Piotr", "Konieczny", "Warszawa", "98010233714", ID::StudentMale, "9876");
    Employee emp2("Piotr", "Narewski", "Sochaczew", "79051074234", ID::EmployeeMale, 2623);
    Employee emp3("John", "Smith", "NewYork", "83091644917", ID::EmployeeMale, 3467);
    Employee emp4("Jacek", "Frydrych", "NewYork", "03282974346", ID::EmployeeMale, 1467);
    Employee emp5("Helena", "Zez", "Opole", "91031583965", ID::EmployeeMale, 3322);
    Student stud4("Krzysztof", "Bukowski", "Torun", "03222576535", ID::StudentMale, "2869");
    Employee emp6("Teodora", "Kamyk", "Kamion", "03310167447", ID::EmployeeMale, 10731);
    uniDb.addStudent(stud2);
    uniDb.addStudent(stud3);
    uniDb.addEmployee(emp5);
    uniDb.addEmployee(emp6);
    uniDb.addStudent(stud4);
    uniDb.addEmployee(emp1);
    uniDb.addEmployee(emp2);
    uniDb.addStudent(stud1);
    uniDb.addEmployee(emp3);
    uniDb.addEmployee(emp4);

    std::vector<size_t> expected{1467, 2623, 3322, 3467, 5678, 10731};
    uniDb.sortByEarnings();
    std::vector<size_t> earnings;

    for (const auto& pers : uniDb.db_) {
        if (pers->getEarnings() != 0) {
            earnings.push_back(pers->getEarnings());
        }
    }

    ASSERT_EQ(earnings, expected);
}

TEST(sortByPeselTest, SortsPeselInAscendingOrder) {
    //test on the data given in the text sortByEarningsTest
    std::vector<std::string> expected{"47052253642",
                                      "79051074234",
                                      "83091644917",
                                      "91031583965",
                                      "98010233714",
                                      "01241249667",
                                      "02322962488",
                                      "03222576535",
                                      "03282974346",
                                      "03310167447"};
    uniDb.sortByPesel();
    std::vector<std::string> pesel;

    for (const auto& pers : uniDb.db_) {
        pesel.push_back(pers->getPesel());
    }

    ASSERT_EQ(pesel, expected);
}

TEST(sortBySurnameTest, SortsSurnameInAscendingOrder) {
    uniDb.db_.clear();
    Student stud1("Ala", "Cccd", "Warszawa", "47052253642", ID::StudentFemale, "5678");
    Student stud2("Adam", "ZZZZ", "Warszawa", "01241249667", ID::StudentMale, "1234");
    Employee emp1("Jan", "aBBB", "Sochaczew", "02322962488", ID::EmployeeMale, 5678);
    Student stud3("Piotr", "bacB", "Warszawa", "98010233714", ID::StudentMale, "9876");
    Employee emp2("Piotr", "aBCB", "Sochaczew", "79051074234", ID::EmployeeMale, 2623);
    Employee emp3("John", "Dada", "NewYork", "83091644917", ID::EmployeeMale, 3467);
    Employee emp4("Jacek", "CcCC", "NewYork", "03282974346", ID::EmployeeMale, 1467);
    Employee emp5("Helena", "Aabb", "Opole", "91031583965", ID::EmployeeMale, 3322);
    Student stud4("Krzysztof", "baba", "Torun", "03222576535", ID::StudentMale, "2869");
    Employee emp6("Teodora", "Dbda", "Kamion", "03310167447", ID::EmployeeMale, 10731);
    uniDb.addStudent(stud2);
    uniDb.addStudent(stud3);
    uniDb.addEmployee(emp5);
    uniDb.addEmployee(emp6);
    uniDb.addStudent(stud4);
    uniDb.addEmployee(emp1);
    uniDb.addEmployee(emp2);
    uniDb.addStudent(stud1);
    uniDb.addEmployee(emp3);
    uniDb.addEmployee(emp4);

    std::vector<std::string> expected{"Aabb",
                                      "aBBB",
                                      "aBCB",
                                      "baba",
                                      "bacB",
                                      "CcCC",
                                      "Cccd",
                                      "Dada",
                                      "Dbda",
                                      "ZZZZ"};
    uniDb.sortBySurname();
    std::vector<std::string> surname;

    for (const auto& person : uniDb.db_) {
        surname.push_back(person->getSurname());
    }

    ASSERT_EQ(surname, expected);
}

