#include "Game.h"
#include "gui.h"
#include "Ball.h"
#include <fstream>
#include <iostream>>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

Game::Game(GUI* gui)
{
    this->gui = gui;
    //player1.setBoard(board);
     //player2.setBoard(board);
     readConfig();
     setConfig();
     //board = new Board();
     player1 = new Player(board);
     player2 = new Player(board);
     createBalls();
     setInitialCoordinates();
}
void Game::readConfig(){
    ifstream inFile;
    inFile.open("F:\\Pulpit\\programowanie\\C++\\bilard-9v\\bilard\\bilard_test\\conf.txt");
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
void Game::hit(int v, int z)
{   
        int dx = v;
        int dy = z;
        int x = gui->getGUIX(balls.at(0)->getX());
        int y = gui->getGUIY(balls.at(0)->getY());
        balls.at(0)->setDX(dx);
        balls.at(0)->setDY(dy);
        z = z * -1;
    for (int i = 28; i > 0; i--) {
        x = x + dx;
        y = y + dy;
        gui->print("x oraz y sa rowne");
        gui->print(x);
        gui->print(y);
        gui->print("dx oraz dy sa rowne");
        gui->print(dx);
        gui->print(dy);
        balls.at(0)->setX(x);
        balls.at(0)->setChanged(true);
        balls.at(0)->setY(y);
        gui->refresh();
        gui->delay(500);
     }
}
void Game::printWidth(){
    cout << board.getWidth();
}
void Game::setConfig(){
    board.setHeight(configMap["board-height"]);
    board.setWidth(configMap["board-width"]);
    board.setCof(configMap["board-cof"]);
    gui->setScreenHeight(configMap["screen-height"]);
    gui->setScreenWidth(configMap["screen-width"]);
}
void Game::createBalls(){
    int r = configMap["radius"];
    for(int i=0; i<16; i++){
        Ball* ball = new Ball(r,i);
        balls.push_back(ball);
    }
}
void Game::setInitialCoordinates() {
    /* wspolrzedne dla i=0; j=0; */
    int rackX = ((board.getWidth() * 3) / 4);
    int rackY = board.getHeight() / 2;
    /* ustawianie pozycji bia³ej i czarnej kuli*/
    balls.at(0)->setOnBoard(true);
    balls.at(0)->setX(board.getWidth() - rackX);
    balls.at(0)->setY(rackY);

    int r = configMap["radius"];
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < j+1; i++) {
            int poz;
            do {
                if (j==2 && i==1) poz = 8;
                else poz = rand() % 16;
            } while (balls.at(poz)->isOnBoard());
            balls.at(poz)->setOnBoard(true);
            balls.at(poz)->setX(rackX + (sqrt(3) * r * j));
            balls.at(poz)->setY(rackY + ( (j * r) - (2 * i * r)));
            /* balls.at(poz)->setX(rackX + (i * r * sqrt(3)));
            balls.at(poz)->setY(rackY + ((i * r) - (2 * j * r))); */
        }

    }
}

void Game::setGUI(GUI* gui)
{
    this->gui = gui;
}

Board* Game::getBoard()
{
    return &board;
}
vector<Ball*>* Game::getBalls()
{
    return &balls;
}