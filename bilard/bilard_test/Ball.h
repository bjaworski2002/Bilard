#ifndef BALL_H
#define BALL_H
#include "Board.h"

enum Color{WHITE, YELLOW, BLUE, RED, ORANGE, PURPLE, GREEN, BROWN, BLACK};
enum Type{SOLID, STRIPED};
class Ball
{
    private:
        double r;
        double x;
        double y;
        double dx;
        double dy;
        double v0;
        //Color color;
        int number;
        //Type type;
        int speed;
        int angle;
        bool onBoard;
        bool changed;
        Board* board;
    public:
        Ball(double r, int number, Board* board);
        bool isTouchingEdge(Board &board);
        bool isTouchingAnotherBall(Ball b);
        void print();
        void hit();
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
        double getRadius();
        double getX();
        double getY();
        double getDX();
        double getDY();
        void setX(double x);
        void setY(double y);
        void setDX(double dx);
        void setDY(double dy);
        void setOnBoard(bool onBoard);
        void setChanged(bool changed);
        int getNumber();
        double getSpeed();
        double getAngle();
        int getGUICoordinateX(int guiWidth, Board board);
        int getGUICoordinateY(int guiHeight, Board board);
        bool hasChanged();
        double getVX(double t);
        double getVY(double t);
        double getX(double t);
        double getY(double t);


};

#endif // BALL_H
