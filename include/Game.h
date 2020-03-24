#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include <map>
#include <string>
using namespace std;

class Game
{
    private:
        Board board;
//        Player player1(Board &board);
//        Player player2(Board &board);
        Player *player1;
        Player *player2;
        int intervalTime;
        map<string, int> configMap;

    public:
        Game();
        void start();
        void readConfig();
        int printWidth();
        void setConfig();
    private:
};

#endif // GAME_H
