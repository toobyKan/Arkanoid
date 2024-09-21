#include "../includes/Paddle.hpp"


PaddlePiece::PaddlePiece(){
    y = x = 6;
    this->icon = '#';
}

PaddlePiece::PaddlePiece(int y, int x){
    this->y = y;
    this->x = x;
    this->icon = '#';
}

Paddle::Paddle(){
    length = 16;
}

Paddle::Paddle(int length){
    this->length = length;
}

PaddlePiece Paddle::rightPiece(){
    return player.back();
}

PaddlePiece Paddle::leftPiece(){
    return player.front();
}

void Paddle::addtoright(PaddlePiece piece){
    player.push_back(piece);
}

void Paddle::addtoleft(PaddlePiece piece){
    player.push_front(piece);
}

void Paddle::removeleft(){
    player.pop_front();
}

void Paddle::removeright(){
    player.pop_back();
}

int Paddle::getLength(){
    return length;
}

