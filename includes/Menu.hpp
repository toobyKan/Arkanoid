#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <ncurses.h>

class Menu {
public:
    Menu();

    void display();
    void clearMenu();
    void handleArrowKey(int);

    int getUserChoice();
    int getSelectedIndex() const;

private:
    std::vector<std::string> choices;
    size_t currentChoice;
};

#endif