#include "Game.h"
#include <fstream>
#include <iostream>>
#include <cstdlib>

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
}
void Game::readConfig(){
    ifstream inFile;
    inFile.open("conf.txt");
    if (!inFile)
    {
        cerr << "Unable to open file conf.txt";
        exit(1);
    }
    string key;
    int value;
    string devnull;
    while(inFile){
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
    player1->printWidth();
}
int Game::printWidth(){
    cout << board.getWidth();
}
void Game::setConfig(){
    board.setHeight(configMap["board-height"]);
    board.setWidth(configMap["board-width"]);
    board.setCof(configMap["board-cof"]);
}
