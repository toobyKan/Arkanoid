#include "../includes/Ball.hpp"


Ball::Ball(){
    y = x = 15;
    this->icon = 'O';
}

Ball::Ball(int y, int x){
    this->y = y;
    this->x = x;
    this->icon = 'O';
}

void Ball::move(){
    this->y += dy;
    this->x += dx;
}   

void Ball::reversedx(){
    dx = -dx;
}

void Ball::reversedy(){
    dy = -dy;
}

// Required for the paddle //
void Ball::rightdx(){
    dx = 1;
}

void Ball::leftdx(){
    dx = -1;
}
/////////////////////////////

