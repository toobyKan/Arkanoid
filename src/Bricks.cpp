#include <ncurses.h>
#include <vector>

#include "../includes/Bricks.hpp"



Brick::Brick(int y, int x){
    this->y = y;
    this->x = x;
    this->icon = 'H';
}

void Brick::changeIcon(chtype icon){
    this->icon = icon; 
}

