#include "gui.h"
#include "Board.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QString>
#include <QGraphicsSimpleTextItem>

GUI::GUI()
{
     scene = new QGraphicsScene();
     view = new QGraphicsView(scene);
     printHeight = 0;
}
void GUI::init(){
       QGraphicsRectItem* rect = new QGraphicsRectItem();
       rect->setRect(0, 0, screenWidth, screenHeight);
       rect->setBrush(Qt::darkGreen);
       scene->addItem(rect);

       for (int i = 0; i < 10; i++) {
           QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
           ellipse->setRect(10 + 24 * i, 10 + 24 * i, 30, 30);
           ellipse->setBrush(Qt::darkRed);
           scene->addItem(ellipse);
       }


}
void GUI::refresh(){}
void GUI::show(){
    view->show();
}

void GUI::setBoard(Board* board)
{
    this->board = board;
}

Board* GUI::getBoard()
{
    return board;
}

void GUI::print(std::string s)
{
    QString qs = QString::fromStdString(s);
    QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
    text->setText(qs);
    text->setPos(0, printHeight);
    scene->addItem(text);
    printHeight = printHeight + 20;
}
void GUI::print(int a)
{
    std::string s = std::to_string(a);
    QString qs = QString::fromStdString(s);
    QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
    text->setText(qs);
    text->setPos(0, printHeight);
    scene->addItem(text);
    printHeight = printHeight + 20;
}

void GUI::setScreenHeight(int screenHeight)
{
    this->screenHeight = screenHeight;
}

void GUI::setScreenWidth(int screenWidth)
{
    this->screenWidth = screenWidth;
}
