#pragma once
#include <iostream>
#include <string>

class MenuItem {
public:
    //Constructor & Destructor
    MenuItem();
    MenuItem(std::string, int);

    // Get title
    std::string getTitle();

    // Get index
    int getIndex();

private:
    // Menu Item Title
    std::string title_;

    // Menu Item Index
    int index_ = 0;
};
