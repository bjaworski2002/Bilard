//#include <iostream>
#include "Game.h"
#include "gui.h"
//#include "Board.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <Windows.h>
using namespace std;

/* int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);

    QGraphicsRectItem* rect = new QGraphicsRectItem();
    rect->setRect(0, 0, 600, 300);
    rect->setBrush(Qt::darkGreen);
    scene->addItem(rect);

    for (int i = 0; i < 10; i++) {
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
        ellipse->setRect(10 + 24 * i, 10 + 24 * i, 30, 30);
        ellipse->setBrush(Qt::darkRed);
        scene->addItem(ellipse);
    }


    view->show();

    return a.exec();
} */

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    srand(time(0));

    GUI gui;
    Game game(&gui);
    gui.setBoard(game.getBoard());
    gui.setBalls(game.getBalls());
    gui.init();
    gui.show();
    game.start();
    //gui.print(gui.getBoard()->getHeight());
    //gui.print(gui.getBoard()->getWidth());
 //   gui.refresh();
    gui.delay(2000);
 //   gui.show2();
   /* for (int i = 0; i < 1000; i=i+10) { */
    //    game.hit(10, 0);
    //}
    game.hit(10, 10);
    return a.exec(); 
}
