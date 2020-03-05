#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Ball.h"
class Player
{
    private:

//        vector<Ball>
        Type type;

    public:
        Player();
        bool hit(int angle, int speed);
        bool isWinner();
        bool isSolid();
        bool isStriped();
};

#endif // PLAYER_H
