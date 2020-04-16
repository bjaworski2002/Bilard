#ifndef GUI_H
#define GUI_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QString>
#include <QGraphicsSimpleTextItem>
#include "Board.h"
class GUI
{
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Board* board;
    int printHeight;
    int screenHeight;
    int screenWidth;
public:
    GUI();
    void init();
    void refresh();
    void show();
    void setBoard(Board* board);
    Board* getBoard();
    void print(std::string s);
    void print(int a);
    void setScreenHeight(int screenHeight);
    void setScreenWidth(int screenWidth);
};

#endif // GUI_H
