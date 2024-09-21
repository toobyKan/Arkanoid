#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <ncurses.h>

class Drawable{
public:
    Drawable();
    Drawable(int, int, chtype);

    int getX();
    int getY();
    chtype getIcon();

protected:
    int y, x;
    chtype icon;
};

#endif