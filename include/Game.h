#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"

class Game
{
    protected:
        Board board();
        Player player1;
        Player player2;
        int intervalTime;

    public:
        Game();
        void start();
    private:
};

#endif // GAME_H
