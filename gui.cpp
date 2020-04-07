#include "gui.h"
#include "Board.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

GUI::GUI()
{
     scene = new QGraphicsScene();
     view = new QGraphicsView(scene);
}
void GUI::init(Board board){
       QGraphicsRectItem* rect = new QGraphicsRectItem();
       rect->setRect(0, 0, board.getWidth(), board.getHeight());
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
