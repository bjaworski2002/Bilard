#include "Board.h"

Board::Board()
{
    //ctor
}
int Board::getWidth(){
    return width;
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
