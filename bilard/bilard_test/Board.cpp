#include "Board.h"

Board::Board()
{
    //ctor
}
int Board::getWidth(){
    return width;
}
int Board::getHeight(){
    return height;
}
void Board::setHeight(int height){
    this->height=height;
}
void Board::setWidth(int width){
    this->width=width;
}
void Board::setCof(int cof){
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
int Board::getCof() {
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
