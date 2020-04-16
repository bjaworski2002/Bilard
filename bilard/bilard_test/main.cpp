//#include <iostream>
#include "Game.h"
#include "gui.h"
//#include "Board.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
//using namespace std;

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

    GUI gui;
    Game game(&gui);
    gui.setBoard(game.getBoard());
    //game.setGUI(&gui);
    gui.init();
    gui.show();
    game.start();
    gui.print(gui.getBoard()->getHeight());
    gui.print(gui.getBoard()->getWidth());
    return a.exec(); 
}
