#include "DataBase.hpp"

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
    EXPECT_EQ(test_string, "fruit");

    uniDb.changeToSmall(test_string_first);
    EXPECT_EQ(test_string_first, "abcde");

    uniDb.changeToSmall(test_string_second);
    EXPECT_EQ(test_string_second, "abcdef");
}
