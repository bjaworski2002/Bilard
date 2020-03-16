#include "Ball.h"

Ball::Ball(int r, int number)
{
    this->r=r;
    this->number=number;
    onBoard=true;
    speed=0;
}
bool isOnBoard(){
    return isOnBoard;
}
bool isWhite(Color color){
    if(color==WHITE) return true;
    else return false;
}
bool isBlack(Color color){
    if(color==BLACK) return true;
    else return false;
}
bool isSolid(Type type){
    if(type=SOLID) return true;
    else return false;
}
bool isStriped(Type type){
    if(type=STRIPED) return true;
    else return false;
}
Color getcolor(Color color){
    return color;
}
Type gettype(Type type){
    return type;
}
int getX(int x){
    return x;
}
int getY(int y){
    return y;
}
int getNumber(int number){
    return number;
}
int getSpeed(int speed){
    return speed;
}
int getAngle(int angle){
    return angle;
}
