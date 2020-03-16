#ifndef BALL_H
#define BALL_H

enum Color{WHITE, YELLOW, BLUE, GREEN, ORANGE, RED, PURPLE, BLACK};
enum Type{STRIPED, SOLID};
class Ball
{
    private:
        int r;
        int x;
        int y;
        Color color;
        int number;
        Type type;
        int speed;
        int angle;
        bool onBoard;
    public:
        Ball(int r, int number);
        bool isTouchingEdge();
        bool isTouchingAnotherBall(Ball b);
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
        Color getcolor();
        Type gettype();
//        getRadius();
        int getX();
        int getY();
        int getNumber();
        int getSpeed();
        int getAngle();

};

#endif // BALL_H
