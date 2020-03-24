#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

Player::Player(Board &board){
    this->board=board;
}
void Player::setBoard(Board &board){
    this->board=board;
}
void Player::printWidth(){
    cout << board.getWidth() << endl;
}
