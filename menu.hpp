#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include "menu_item.hpp"

class Menu {
public:
    //Constructor
    Menu(std::string);

    bool getDoNotExit();
    void setDoNotExit(bool);

    void setBody(const std::string&);

    // Functions
    void printHeader();
    void printBody();
    void printFooter();
    void printContinue();
    size_t printMenu();
    void addItem(std::string);  // Add item with title
    void optNotImplemented();
    void optVoid();

private:
    void clearScreen();
    std::string header_;
    std::string body_;
    std::string footer_;
    // Menu items
    std::vector<MenuItem*> menuItems_;

    bool doNotExit_ = true;
};