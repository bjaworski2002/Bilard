#include "Board.h"

Board::Board()
{
    //ctor
}
double Board::getWidth(){
    return width;
}
double Board::getHeight(){
    return height;
}
void Board::setHeight(double height){
    this->height=height;
}
void Board::setWidth(double width){
    this->width=width;
}
void Board::setCof(double cof){
    this->cof=cof;
}
void Board::setG(double g)
{
    this->g = g;
}
double Board::getG()
{
	return g;
}
double Board::getCof() {
    return cof;
}
//void Board::createBalls(){
//
//    for(int i=0; i<16; i++){
//        ball = new Ball(,i)
//        balls.push_back();
//        balls.at(i)->number=i;
//    }
//}
