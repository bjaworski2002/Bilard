#include "Ball.h"
#include "Board.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include <random>
#include <cstdlib>

using namespace std;

Ball::Ball(double r, int number, Board* board)
{
    dx = 0;
    dy = 0;
    x = 0;
    y = 0;
    this->r=r;
    this->number=number;
    this->board = board;
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
double Ball::getX(){
    return x;
}
double Ball::getY(){
    return y;
}
double Ball::getRadius(){
    return r;
}
double Ball::getDX()
{
    return dx;
}
double Ball::getDY()
{
    return dy;
}
void Ball::setX(double x){
    //this->dx = x - this->x;
    this->x = x;
}
void Ball::setY(double y){
    //this->dy = y - this->y;
    this->y=y;
}
void Ball::setDX(double dx)
{
    this->dx = dx;
}
void Ball::setDY(double dy)
{
    this->dy = dy;
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
double Ball::getSpeed(){
    return speed;
}
double Ball::getAngle(){
    return angle;
}
bool Ball::isTouchingEdge(Board &board) {
     if (x<=r || x >= board.getWidth() - r || y <= r || y >= board.getHeight() - r) return true; 
    else return false;
} 
bool Ball::isTouchingAnotherBall(Ball b) {
    double x1 = abs(x - b.getX());
    double y1 = abs(y - b.getY());
    if (sqrt((x1 * x1) + (y1 * y1) <= 2 * r)) { return true; }
    else return false;
}

bool Ball::hasChanged(){
    return changed;
}

double Ball::getVX(double t)
{   
    double a = board->getCof() * board->getG();
    double ax = a * cos(angle);

    double v0x = v0 * cos(angle);

    return v0x + (ax*t); 
}

double Ball::getVY(double t)
{
    double a = board->getCof() * board->getG();
    double ay = a * sin(angle);
    double v0y = v0 * sin(angle);
    return v0y + (ay * t);;
}

double Ball::getX(double t)
{
    double a = board->getCof() * board->getG();
    double ax = a * cos(angle);
    double v0x = v0 * cos(angle);
    return x+v0x*t + (ax * (t*t) / 2);
}
double Ball::getY(double t)
{
    double a = board->getCof() * board->getG();
    double ay = a * sin(angle);
    double v0y = v0 * sin(angle);
    return y + v0y * t + (ay * (t * t) / 2);
}