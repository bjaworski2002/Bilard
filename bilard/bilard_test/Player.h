#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "Ball.h"
#include "Board.h"

using namespace std;
class Player
{
    private:
        std::vector<Ball> balls;
        Type type;
        Board board;
    public:
        Player(Board &board);
        void print();
        bool hit(int angle, int speed);
        bool isWinner();
        bool isSolid();
        bool isStriped();
        void setBoard(Board &board);
        void printWidth();
};

#endif // PLAYER_H
