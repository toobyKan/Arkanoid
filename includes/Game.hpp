#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

#include "Board.hpp"
#include "Bricks.hpp"
#include "Empty.hpp"
#include "Ball.hpp"
#include "Paddle.hpp"

class Game{
public:
    Game(int, int, int);

    bool getMenuMode();
    void menuToggle();
    void buildPlayer(int, int);
    void buildMap();
    void buildBricks(int, int);
    void processInput();
    void updateState();

    void detectCollision();

    void PaddleMoveRight();
    void PaddleMoveLeft();

    void redraw();
    void redraw_broder();

    void endGame();
    bool isOver();

private:
    Board board;
    Paddle player;
    Ball ball;
    bool game_over;
    bool menu_mode;
};

#endif