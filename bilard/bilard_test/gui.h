#ifndef GUI_H
#define GUI_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QString>
#include <QGraphicsSimpleTextItem>
#include <vector>
#include "Board.h"
#include "Ball.h"
class GUI
{
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Board* board;
    std::vector<Ball*>* balls;
    std::vector<QGraphicsEllipseItem*> guiBalls;
    int printHeight;
    int screenHeight;
    int screenWidth;
public:
    GUI();
    void init();
    void delay(int ms);
    void refresh();
    void show();
    void show2();
    void setBoard(Board* board);
    void setBalls(std::vector<Ball*>* balls);
    Board* getBoard();
    void print(std::string s);
    void print(int a);
    void printBall(int i, int x, int y);
    void setScreenHeight(int screenHeight);
    void setScreenWidth(int screenWidth);
    int getGUIX(int x);
    int getGUIY(int y);
    int getGUIR(int r);
    void hideBalls();
    void refreshBalls();
    QBrush getQTColor(Color color);
};

#endif // GUI_H
