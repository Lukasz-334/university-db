#include "menu_item.hpp"

MenuItem::MenuItem() {
    title_ = "Undefined";
}

MenuItem::MenuItem(std::string initTitle, int initIndex) {
    // Set title
    title_ = initTitle;

    // Set index
    index_ = initIndex;
}

int MenuItem::getIndex() {
    return index_;
}

std::string MenuItem::getTitle() {
    return title_;
}
