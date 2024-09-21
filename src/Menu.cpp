#include "../includes/Menu.hpp"

Menu::Menu(){
    keypad(stdscr, TRUE);

    choices = {"Start Game", "Exit"};
    currentChoice = 0;
}

void Menu::clearMenu(){
        clear();
        refresh();
}

void Menu::display(){
    clear();

    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

    int startRow = maxY / 2 - choices.size() / 2;

    for (size_t i = 0; i < choices.size(); ++i)
    {
        int startCol = maxX / 2 - choices[i].length() / 2;

        if (i == currentChoice)
        {
            mvprintw(startRow + i, startCol - 3, ">> ");
        }

        mvprintw(startRow + i, startCol, "%s", choices[i].c_str());
    }

    refresh();
}

void Menu::handleArrowKey(int key){
    switch (key)
    {
    case KEY_UP:
        currentChoice = (currentChoice == 0) ? choices.size() - 1 : currentChoice - 1;
        break;
    case KEY_DOWN:
        currentChoice = (currentChoice + 1) % choices.size();
        break;
    }
}

int Menu::getUserChoice(){
    return getch();
}

int Menu::getSelectedIndex() const{
    return currentChoice;
}
