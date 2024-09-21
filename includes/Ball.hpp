#ifndef BALL_H
#define BALL_H

#include "Drawable.hpp"

class Ball : public Drawable{
public:
    Ball();
    Ball(int, int);
    void move();
    void reversedx();
    void reversedy();
    // Required for the paddle //
    void rightdx();
    void leftdx();
    /////////////////////////////

private:
    int dx = 1;
    int dy = 1;
};

#endif