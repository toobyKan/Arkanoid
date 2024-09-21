#include "../includes/Game.hpp"
#include <iostream>

int level[10][14] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


Game::Game(int height, int width, int timeout){
    board = Board(height, width, timeout);
    board.initialize();
    game_over = false;
    menu_mode = true;
    ball = Ball();
    player = Paddle(); 
    buildMap();

    int row = height - height/8;
    int col = width/2-player.getLength()/2;
    buildPlayer(col, row);
}

bool Game::getMenuMode(){
    return menu_mode;
}

void Game::menuToggle(){
    menu_mode = !menu_mode;
}

void Game::buildPlayer(int col, int row){
    for(int i = 0; i < player.getLength(); i++){
        PaddlePiece piece = PaddlePiece(row, col + i);
        board.add(piece);
        player.addtoright(piece);
    }
}

void Game::buildMap(){
    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 14; col++){
            buildBricks(row,col);
        }    
    }
}

void Game::buildBricks(int row, int col){
    if(level[row][col] > 0){
        for(int bricklen = 0; bricklen < 7; bricklen++){
            board.add(Brick(row+1, col*7+bricklen+1)); 
        } 
    }
    else{
        for(int bricklen = 0; bricklen < 7; bricklen++){
            board.add(Empty(row+1, col*7+bricklen+1));  
        }
    }
}

void Game::processInput(){
    chtype input = board.getInput();
    switch(input){
        case KEY_LEFT:
        case 'a':
            if(player.leftPiece().getX() > 2){
                PaddleMoveLeft();
                PaddleMoveLeft();
            }
            else if(player.leftPiece().getX() == 2){
                PaddleMoveLeft();
            }
            break;
        
        case KEY_RIGHT:
        case 'd':
            if(player.rightPiece().getX() < board.getWidth()-3){
                PaddleMoveRight();
                PaddleMoveRight();
            }
            else if(player.rightPiece().getX() == board.getWidth()-3){
                PaddleMoveRight();
            }
            break;
        case 'm':
            menuToggle(); 
            break;
        default:
            break;
    }
}

void Game::updateState(){
    board.add(Empty(ball.getY(), ball.getX()));
    ball.move();
    board.add(ball);

    detectCollision();
}

void Game::detectCollision(){

    if(ball.getX() <= 1 || ball.getX() >= board.getWidth()-2){ //In Border
        ball.reversedx();
        if(ball.getX() <= 0 || ball.getX() >= board.getWidth()-1){ //Out of Border case  
            ball.move();
            redraw_broder(); 
        } 
    }

    if(ball.getY() <= 1) ball.reversedy(); //Roof

    if(ball.getY() >= board.getHeight() - 1) endGame(); //Floor

    if(ball.getY() <= 10){
        if(level[ball.getY()-1][(ball.getX()-1)/7] > 0){    //Finding the Brick in the level matrix
            level[ball.getY()-1][(ball.getX()-1)/7] -= 1;   //Take away one life
            buildBricks(ball.getY()-1, (ball.getX()-1)/7);  //Redraw that Brick
            ball.reversedy();                               //Ricochet 
        }
    }

    else if(ball.getY() == player.rightPiece().getY() - 1){ // height check for the player
        if(ball.getX() <= player.rightPiece().getX() &&                             
            ball.getX() >= player.rightPiece().getX() - player.getLength()/4){ // 1/4 of the player from the right
                ball.reversedy(); //flies o the right
                ball.rightdx();
            }

        else if(ball.getX() >= player.leftPiece().getX() - 1 &&
            ball.getX() <= player.leftPiece().getX() + player.getLength()/4){ // 1/4 of the player from the left
                ball.reversedy();   //flies to the left
                ball.leftdx();
            }
        else if(ball.getX() > player.leftPiece().getX() + player.getLength()/4 && 
            ball.getX() < player.rightPiece().getX() - player.getLength()/4){ // the mid section
                ball.reversedy();   // ricochet's normally
            }
    }
}

void Game::PaddleMoveRight(){
    board.add(Empty(player.leftPiece().getY(), player.leftPiece().getX()));
    player.removeleft();
    PaddlePiece next = PaddlePiece(player.rightPiece().getY(), player.rightPiece().getX() + 1);
    board.add(next);
    player.addtoright(next);
}

void Game::PaddleMoveLeft(){
    board.add(Empty(player.rightPiece().getY(), player.rightPiece().getX()));
    player.removeright();
    PaddlePiece next = PaddlePiece(player.leftPiece().getY(), player.leftPiece().getX() - 1);
    board.add(next);
    player.addtoleft(next);
}

void Game::redraw(){
    board.refresh();
}

void Game::redraw_broder(){
    board.addBorder();
}

void Game::endGame(){
    game_over = !game_over;
}

bool Game::isOver(){
    return game_over;
}

