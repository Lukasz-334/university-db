#include "student.hpp"

Student::Student(std::string name, std::string surname, std::string address, unsigned int index, size_t pesel, char gender)
: name_(name)
, surname_(surname)
, address_(address)
, index_(index)
, pesel_(pesel)
, gender_(gender)
{}