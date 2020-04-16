#include "Player.h"
#include "Board.h"
#include <iostream>

using namespace std;

Player::Player(Board &board){
    this->board=board;
}
void Player::print(){
//    cout << "Kule dla wektora balls: " << endl;
//    for(int i=0; i<balls.size(); i++){
//        balls.at(i).print();
//    }
    cout << "Typ: " << type << "Stol: " << &board << endl;
}
void Player::setBoard(Board &board){
    this->board=board;
}
void Player::printWidth(){
    cout << board.getWidth() << endl;
}
