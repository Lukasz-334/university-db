#pragma once
#include <memory>
#include <vector>
#include "Employee.hpp"
#include "Person.hpp"
#include "Student.hpp"

class DataBase {
private:
    using dataVector = std::vector<std::unique_ptr<Person>>;

public:
    dataVector db_ = {};
    explicit DataBase() = default;
    DataBase(size_t size);
    void changeToSmall(std::string&);
    size_t stringToDouble(const std::string&);
    bool testPesel(const std::string&);
    bool checkPesel(size_t);

    bool searchPesel(const std::string&);
    std::vector<Person*> searchSurname(const std::string&);

    bool addEmployee(const Employee&);
    bool addStudent(const Student&);
    bool deleteStudent(const std::string&);

    void sortByEarnings();
    void sortByPesel();
    void sortBySurname();

    bool modificationOfEarnings(const std::string&, const size_t&);
    void printDb(); 
    void saveDbToFile(const std::string&);
};

    /*

   
    Dodawanie nowych studentów OK ( w 2 wersji dodawanie studenta i pracownika ) OK
    Wyświetlanie całej bazy danych 
    
    Wyszukiwanie po nazwisku OK
    Wyszukiwanie po numerze PESEL OK
    
    Sortowanie po numerze PESEL OK(rosnąco od najstarszych do najmłodszych)
    Sortowanie po nazwisku OK
    Sortowanie po zarobkach (problematyczne) OK
    
    Usuwanie po numerze indeksu OK 
    Walidacja czy numer PESEL jest poprawny Wiki - poprawność PESEL (trudne) OK
    Wczytywanie z pliku i zapisywanie całej bazy w pliku (trudne)
    
    Przechowywanie rekordów pracowników uczelni o strukturze: imię, nazwisko, PESEL, płeć, adres, zarobki
    Wszystkie osoby niezależnie czy będą to pracownicy, czy studenci mają być trzymani w jednym kontenerze
    Wypełnianie bazy danych sztucznymi danymi (generowanie danych)
    Modyfikacja zarobków wyszukując osobę po numerze PESEL (problematyczne) Jest ok ale można ulepszyć
    po dopisaniu zmiennej statycznej static string type_of_person = "student"; 
    static string type_of_person = "employee";







*/