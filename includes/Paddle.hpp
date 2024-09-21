#ifndef TIME_H
#define TIME_H

#include <ncurses.h>
#include <deque>

#include "Drawable.hpp"

class PaddlePiece : public Drawable{
public:
    PaddlePiece();
    PaddlePiece(int, int);
};

class Paddle{
public:
    Paddle();
    Paddle(int);

    PaddlePiece rightPiece();
    PaddlePiece leftPiece();

    void addtoright(PaddlePiece);
    void addtoleft(PaddlePiece);

    void removeleft();
    void removeright();

    int getLength();

private:
    int length;
    std::deque<PaddlePiece> player;
};

#endif