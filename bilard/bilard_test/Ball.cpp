#include "Ball.h"
#include <iostream>

using namespace std;

Ball::Ball(int r, int number)
{
    this->r=r;
    this->number=number;
    onBoard=false;
    speed=0;
}
void Ball::print(){
    cout << "Kula: promien: " << r << "pozycja x: " << x << "pozycja y: " << y << "numer: " << number << "predkosc: " << speed << "onboard:  " << onBoard << endl;
}
bool Ball::isOnBoard(){
    return onBoard;
}
bool Ball::isWhite(){
    if(getColor()==WHITE) return true;
    else return false;
}
bool Ball::isBlack(){
    if(getColor()==BLACK) return true;
    else return false;
}
bool Ball::isSolid(){
    if(getType()==SOLID) return true;
    else return false;
}
bool Ball::isStriped(){
    if(getType()==STRIPED) return true;
    else return false;
}
Color Ball::getColor(){
    if(number>8) number=number-8;
    return (Color)number;
}
Type Ball::getType(){
    if(number<=8) return SOLID;
    else return STRIPED;
}
int Ball::getX(){
    return x;
}
int Ball::getY(){
    return y;
}
int Ball::getRadius(){
    return r;
}
void Ball::setX(int x){
    this->x=x;
}
void Ball::setY(int y){
    this->y=y;
}
void Ball::setOnBoard(bool onBoard){
    this->onBoard=onBoard;
}
int Ball::getNumber(){
    return number;
}
int Ball::getSpeed(){
    return speed;
}
int Ball::getAngle(){
    return angle;
}
