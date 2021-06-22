#include "menu.hpp"
#include <iostream>
#include <limits>

Menu::Menu(std::string initHeader)
    : header_(initHeader) {}

void Menu::addItem(std::string title) {
    // Create menu item and add to list
    if (menuItems_.size() < UINT8_MAX) {
        menuItems_.push_back(new MenuItem(title, menuItems_.size() + 1));
    } else {
        std::cout << "\nERROR: To many menu items added !!!\n";
    }
}

void Menu::printHeader() {
    clearScreen();
    if (!header_.empty()) {
        std::cout << header_
                  << "\n";
    }
}

void Menu::printBody() {
    if (!body_.empty()) {
        std::cout << body_
                  << "\n";
    }
}

void Menu::printFooter() {
    if (!footer_.empty()) {
        std::cout << "\n"
                  << footer_
                  << "\n";
    } else {
        std::cout << "\n\n";
    }
}

void Menu::printContinue() {
    std::cout << "\nPress Enter to continue ..."
              << "\n";
    std::cin.ignore();
    std::cin.get();  
}

// Print menu and allow for selection
size_t Menu::printMenu() {
    // Initialize option
    std::string tmp_str;
    size_t option = 0;
    printHeader();

    // Enumerate in print options
    for (size_t i = 0; i < menuItems_.size(); i++) {
        std::cout << (i + 1)
                  << ".) "
                  << menuItems_[i]->getTitle()
                  << "\n";
    }

    printFooter();

    // Prompt user for selection
    std::cout << "\nSelect option: ";
    std::getline(std::cin, tmp_str);

    try {
        option = std::stoi(tmp_str);
    } catch (...) {
        option = 0;
    }

    // Check if selection is valid
    if ((option < 1) || (option > menuItems_.size())) {
        // Print selection invalid and print menu again
        footer_ = "ERROR: Not a valid selection.  Please try again.";
        option = 0;
    } else {
        footer_.clear();
    }
    return option;
}

bool Menu::getDoNotExit() {
    return doNotExit_;
}

void Menu::setDoNotExit(bool b) {
    doNotExit_ = b;
}

void Menu::setBody(const std::string& body) {
    body_ = body;
}

void Menu::optNotImplemented() {
    footer_ = "Not implemented yet.";
}

void Menu::optVoid() {}

void Menu::clearScreen() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}