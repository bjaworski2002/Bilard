#ifndef BALL_H
#define BALL_H
#include "Board.h"

enum Color{WHITE, YELLOW, BLUE, RED, ORANGE, PURPLE, GREEN, BROWN, BLACK};
enum Type{SOLID, STRIPED};
class Ball
{
    private:
        int r;
        int x;
        int y;
        int dx;
        int dy;
        int v0;
        int g; /* temp */
        //Color color;
        int number;
        //Type type;
        int speed;
        int angle;
        bool onBoard;
        bool changed;
        Board* board;
    public:
        Ball(int r, int number);
        bool isTouchingEdge(Board &board);
        bool isTouchingAnotherBall(Ball b);
        void print();
        void move();
        bool isMoving();
        void recountPosition();
        void recountVelocity();
        void recountAngle();
        bool isOnBoard();
        bool isWhite();
        bool isBlack();
        bool isSolid();
        bool isStriped();
        Color getColor();
        Type getType();
        int getRadius();
        int getX();
        int getY();
        int getDX();
        int getDY();
        void setX(int x);
        void setY(int y);
        void setOnBoard(bool onBoard);
        void setChanged(bool changed);
        int getNumber();
        int getSpeed();
        int getAngle();
        int getGUICoordinateX(int guiWidth, Board board);
        int getGUICoordinateY(int guiHeight, Board board);
        bool hasChanged();
        int getVX(int t);
        int getVY(int t);


};

#endif // BALL_H
