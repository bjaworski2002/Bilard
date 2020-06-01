#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include "gui.h"
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
        vector<Ball*> balls;
        GUI* gui;
    public:
        Game(GUI* gui);
        void start();
        void hit(int v, int z);
        void readConfig();
        void printWidth();
        void setConfig();
        void createBalls();
        void setInitialCoordinates();
        void setGUI(GUI* gui);
        Board* getBoard();
        vector<Ball*>* getBalls();
    private:
};

#endif // GAME_H
