#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

#include "Drawable.hpp"

class Board{
public:
    Board();
    Board(int, int, int);
    void construct(int);
    void initialize();

    void add(Drawable);
    void addAt(int, int, chtype);
    void addBorder();
    
    chtype getInput();
    int getHeight();
    int getWidth();
    
    void clear();
    void refresh();
    void setTimeout(int);

private:
    int HEIGHT, WIDTH, timeout;
    WINDOW *win;
};

#endif