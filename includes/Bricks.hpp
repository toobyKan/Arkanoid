#ifndef BRICK_H
#define BRICK_H

#include <ncurses.h>
#include <vector>

#include "Drawable.hpp"


class Brick : public Drawable{
    public:
    Brick(int, int);
    void changeIcon(chtype);
};

#endif