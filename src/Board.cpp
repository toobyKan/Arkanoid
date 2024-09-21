#include <ncurses.h>

#include "../includes/Board.hpp"
#include "../includes/Time.hpp"


Board::Board(){
    HEIGHT = 0;
    WIDTH = 0;
    construct(300);
}

Board::Board(int height, int width, int timeout){
    HEIGHT = height;
    WIDTH = width;
    construct(timeout);
}

void Board::construct(int timeout){
    int xMax, yMax;
    getmaxyx(stdscr, yMax, xMax);
    this->win = newwin(HEIGHT, WIDTH, yMax/2 - HEIGHT/2, xMax/2 - WIDTH/2);
    this->timeout = timeout;
    setTimeout(timeout);
    keypad(win, true);
}

void Board::initialize(){
    clear();
    refresh();
}

void Board::add(Drawable drawable){
    addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
}

void Board::addAt(int y, int x, chtype ch){
    mvwaddch(win, y, x, ch);
}

chtype Board::getInput(){
    time_t time_last_input = Time::milliseconds();

    int input = wgetch(win);
    int new_input = ERR;
    setTimeout(0);
    while(time_last_input + timeout >= Time::milliseconds()){
        new_input = wgetch(win);
    }
    setTimeout(timeout);

    if (new_input != ERR){
        input = new_input;
    }
    
    return input;
}

int Board::getHeight(){
    return HEIGHT;
}

int Board::getWidth(){
    return WIDTH;
}

void Board::addBorder(){
    box(win, 0, 0);
}

void Board::clear(){
    wclear(win);
    addBorder();
}

void Board::refresh(){
    wrefresh(win);
}

void Board::setTimeout(int timeout){
    wtimeout(win, timeout);
}

