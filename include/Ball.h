#ifndef BALL_H
#define BALL_H

enum Color{WHITE, YELLOW, BLUE, GREEN, ORANGE, RED, PURPLE, BLACK};
enum Type{STRIPED, SOLID};
class Ball
{
    protected:
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
        Ball();
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
};

#endif // BALL_H
