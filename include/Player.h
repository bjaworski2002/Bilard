#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Ball.h"

using namespace std;
class Player
{
    private:
        vector<Ball> balls;
        Type type;
    public:
        Player();
        bool hit(int angle, int speed);
        bool isWinner();
        bool isSolid();
        bool isStriped();
};

#endif // PLAYER_H
