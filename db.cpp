#include "db.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"

size_t Db::getDbSize() const {
    return db_.size();
}

bool Db::checkPesel(size_t pesel) {
    int multiplication[11] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};
    int sum = 0;
    int tab_pesel[11]{};
    for (int i = 10; i >= 0; i--) {
        tab_pesel[i] = pesel % 10;
        pesel = pesel / 10;
    }
    for (int i = 0; i < 11; i++) {
        sum = tab_pesel[i] * multiplication[i] + sum;
    }
    return ((sum > 0) && (sum % 10 == 0));
}

void Db::addStudent() {
    Student tmp_stud;
    std::string tmp_str;  //tymczasowy string
    size_t tmp_size;      // to zmienne na chwile
    std::cout << "\n Name: ";
    std::cin >> tmp_str;
    tmp_stud.setName(tmp_str);
    std::cout << " Surname: ";
    std::cin >> tmp_str;
    tmp_stud.setSurname(tmp_str);
    std::cout << " Address: ";
    std::cin >> tmp_str;
    tmp_stud.setAddress(tmp_str);
    std::cout << " Index: ";
    std::cin >> tmp_str;
    tmp_stud.setIndex(tmp_str);
    std::cout << " Gender: ";
    std::cin >> tmp_str;
    tmp_stud.setGender(tmp_str);
    std::cout << " PESEL: ";
    std::cin >> tmp_str;
    if (searchPesel(tmp_str)) {
        try {
            tmp_size = std::stod(tmp_str);
        } catch (...) {
            tmp_size = 0;
        }
        if (checkPesel(tmp_size)) {
            tmp_stud.setPesel(tmp_str);
            db_.emplace_back(tmp_stud);
            std::cout << "Student added.\n";
            std::cout << "Number of student in Database: " << getDbSize() << '\n';
        } else {
            std::cout << "\n Student not added. Wrong PESEL !\n";
        }
    } else {
        std::cout << "\n Student with this PESEL already exists!\n";
    }
}

void Db::addStudent(Student& stud) {
    db_.emplace_back(stud);
}

// void Db::sort(const std::string& surname) {
// }

// void Db::sort(size_t pesel) {
// // }

void Db::deleteStud(std::string index) {
    bool studNotFound = true;
    for (std::vector<Student>::iterator it = db_.begin(); it < db_.end(); ++it) {
        if (it->getIndex() == index) {
            std::cout << "Student:\n";
            it->printPersonality();
            db_.erase(it);
            studNotFound = false;
            std::cout << "\nStudent deleted.\n";
        }
    }
    if (studNotFound) {
        std::cout << "Index " << index << " not found.\n";
    }
}

void Db::printDb() {
    if (db_.size() > 0) {
        for (auto& person1 : db_) {
            person1.printPersonality();
        }
    } else {
        std::cout << "No records in database.\n";
    }
}

void Db::searchSurname(const std::string& surname) {
    bool studNotFound = true;
    std::cout << "Searching by surname: " << surname << std::endl;
    for (auto person1 : db_) {
        if (person1.getSurname() == surname) {
            person1.printPersonality();
            studNotFound = false;
        }
    }
    if (studNotFound) {
        std::cout << "Not found.\n";
    }
}

void Db::searchSurnameInMenu() {
    std::string tmp_str;
    std::cout << "Please enter surname: ";
    std::cin >> tmp_str;
    searchSurname(tmp_str);
}

void Db::deleteStudInMenu() {
    std::string tmp_str;
    std::cout << "Please enter index number: ";
    std::cin >> tmp_str;
    deleteStud(tmp_str);
}

bool Db::searchPesel(const std::string& pesel) {
    bool peselNotFound = true;
    std::cout << "Searching by pesel: " << pesel << '\n';
    for (auto person1 : db_) {
        if (person1.getPesel() == pesel) {
            person1.printPersonality();
            peselNotFound = false;
            break;
        }
    }
    if (peselNotFound) {
        std::cout << "Not found.\n";
    }
    return peselNotFound;
}

void Db::searchPeselInMenu() {
    std::string tmp_str;
    size_t tmp_size;
    std::cout << "Please enter PESEL: ";
    std::cin >> tmp_str;
    searchPesel(tmp_str);
}

/* *************************************************/
/* Implementation based on idea from this blog:    */
/* https://lukasjoswiak.com/serializing-stdstring/ */
/* *************************************************/
void Db::saveDbToFile(const std::string& fileDB) {
    std::string::size_type length;
    std::ofstream ofs(fileDB, std::ios::binary);
    std::cout << "Saving " << db_.size() << " students to file: " << fileDB << '\n';
    for (auto person1 : db_) {
        length = person1.getName().length();
        ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));  // the first 8 bytes are used to encode the length of the string
        ofs.write(reinterpret_cast<const char*>(person1.getName().data()), length);     // encode the string itself
        length = person1.getSurname().length();
        ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));  // the first 8 bytes are used to encode the length of the string
        ofs.write(reinterpret_cast<const char*>(person1.getSurname().data()), length);  // encode the string itself
        length = person1.getAddress().length();
        ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));  // the first 8 bytes are used to encode the length of the string
        ofs.write(reinterpret_cast<const char*>(person1.getAddress().data()), length);  // encode the string itself
        length = person1.getIndex().length();
        ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));  // the first 8 bytes are used to encode the length of the string
        ofs.write(reinterpret_cast<const char*>(person1.getIndex().data()), length);    // encode the string itself
        length = person1.getPesel().length();
        ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));  // the first 8 bytes are used to encode the length of the string
        ofs.write(reinterpret_cast<const char*>(person1.getPesel().data()), length);    // encode the string itself
        length = person1.getGender().length();
        ofs.write(reinterpret_cast<const char*>(&length), sizeof(length));  // the first 8 bytes are used to encode the length of the string
        ofs.write(reinterpret_cast<const char*>(person1.getGender().data()), length);   // encode the string itself
    }
    ofs.close();
}

void Db::loadDbFromFile(const std::string& fileDB) {
    std::ifstream ifs(fileDB, std::ios::binary);
    std::string::size_type length;
    std::string tmp_str;
    Student tmp_stud;
    while (ifs.peek()!=EOF) { 
        ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
        tmp_str.resize(length);
        ifs.read(reinterpret_cast<char*>((void *)tmp_str.data()), length);
        tmp_stud.setName(tmp_str);

        ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
        tmp_str.resize(length);
        ifs.read(reinterpret_cast<char*>((void *)tmp_str.data()), length);
        tmp_stud.setSurname(tmp_str);

        ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
        tmp_str.resize(length);
        ifs.read(reinterpret_cast<char*>((void *)tmp_str.data()), length);
        tmp_stud.setAddress(tmp_str);

        ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
        tmp_str.resize(length);
        ifs.read(reinterpret_cast<char*>((void *)tmp_str.data()), length);
        tmp_stud.setIndex(tmp_str);

        ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
        tmp_str.resize(length);
        ifs.read(reinterpret_cast<char*>((void *)tmp_str.data()), length);
        tmp_stud.setPesel(tmp_str);

        ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
        tmp_str.resize(length);
        ifs.read(reinterpret_cast<char*>((void *)tmp_str.data()), length);
        tmp_stud.setGender(tmp_str);

        addStudent(tmp_stud);
    }
    ifs.close();
    std::cout << "Loaded " << db_.size() << " students from file: " << fileDB << '\n';
}