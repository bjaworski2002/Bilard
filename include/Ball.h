#ifndef BALL_H
#define BALL_H

enum Color{WHITE, YELLOW, BLUE, RED, ORANGE, PURPLE, GREEN, BROWN, BLACK};
enum Type{SOLID, STRIPED};
class Ball
{
    private:
        int r;
        int x;
        int y;
        //Color color;
        int number;
        //Type type;
        int speed;
        int angle;
        bool onBoard;
    public:
        Ball(int r, int number);
        bool isTouchingEdge();
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
        void setX(int x);
        void setY(int y);
        void setOnBoard(bool onBoard);
        int getNumber();
        int getSpeed();
        int getAngle();



};

#endif // BALL_H
