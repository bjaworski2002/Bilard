#include "Ball.h"
#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <random>
#include <cstdlib>

using namespace std;

Ball::Ball(int r, int number)
{
    dx = 0;
    dy = 0;
    this->r=r;
    this->number=number;
    onBoard=false;
    /* changed=false;
    if (rand() % 3 == 0) */ changed = false;
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
int Ball::getDX()
{
    return dx;
}
int Ball::getDY()
{
    return dy;
}
void Ball::setX(int x){
    this->dx = x - this->x;
    this->x = x;
}
void Ball::setY(int y){
    this->dy = y - this->y;
    this->y=y;
}
void Ball::setOnBoard(bool onBoard){
    this->onBoard=onBoard;
}
void Ball::setChanged(bool changed)
{
    this->changed = changed;
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
bool Ball::isTouchingEdge(Board &board) {
     if (x<=r || x >= board.getWidth() - r || y <= r || y >= board.getHeight() - r) return true; 
    else return false;
} 
bool Ball::isTouchingAnotherBall(Ball b) {
    int x1 = abs(x - b.getX());
    int y1 = abs(y - b.getY());
    if (sqrt((x1 * x1) + (y1 * y1) <= 2 * r)) { return true; }
    else return false;
}

bool Ball::hasChanged(){
    return changed;
}