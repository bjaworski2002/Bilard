#include "Game.h"
#include <fstream>
#include <iostream>>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

Game::Game(/*Board &board*/)
{
     //player1.setBoard(board);
     //player2.setBoard(board);
     readConfig();
     setConfig();
     //board = new Board();
     player1 = new Player(board);
     player2 = new Player(board);
     createBalls();
}
void Game::readConfig(){
    ifstream inFile;
    inFile.open("C:\\Users\\Bartosz\\Documents\\projekt3\\conf.txt");
    if (!inFile)
    {
        cerr << "Unable to open file conf.txt";
        exit(1);
    }
    string key;
    int value;
    string devnull;
    while(!inFile.eof()){
        inFile >> key >> value >> devnull;
        configMap[key]=value;
        cout << configMap[key] << endl;
    }

//    map<string, int>::iterator it;
//    for( it=configMap.begin(); it!=configMap.end(); ++it )
//    {
//        cout << *it << endl;
//    }
}
void Game::start(){
//    player1->printWidth();
}
int Game::printWidth(){
    cout << board.getWidth();
}
void Game::setConfig(){
    board.setHeight(configMap["board-height"]);
    board.setWidth(configMap["board-width"]);
    board.setCof(configMap["board-cof"]);
}
void Game::createBalls(){
    int r = configMap["radius"];
    for(int i=0; i<16; i++){
        Ball* ball = new Ball(r,i);
        balls.push_back(ball);
    }
}
void Game::setInitialCoordinates(){
    for(int j=0; j<5; j++){
        for(int i=0; i<5-j; i++){
            int poz;
            int r = configMap["radius"];
            do{
                poz = rand() % 16;
            }
            while(balls.at(poz)->isOnBoard());
            balls.at(poz)->setOnBoard(true);
            balls.at(poz)->setX(i*r*sqrt(3));
            balls.at(poz)->setY((i*r)-(2*j*r));
        }

    }
}
