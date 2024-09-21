#ifndef EMPTY_H
#define EMPTY_H

#include <ncurses.h>

#include "Drawable.hpp"

class Empty : public Drawable{
public: 
    Empty(int, int);
};

#endif