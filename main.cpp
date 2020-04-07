#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include "gui.h"
#include "Board.h"
#include "Game.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);


 //   QGraphicsRectItem* rect = new QGraphicsRectItem();
 //   rect->setRect(0, 0, 600, 300);
 //   rect->setBrush(Qt::darkGreen);
 //   scene->addItem(rect);

 /*   for (int i = 0; i < 10; i++) {
        QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
        ellipse->setRect(10 + 24 * i, 10 + 24 * i, 30, 30);
        ellipse->setBrush(Qt::darkRed);
        scene->addItem(ellipse);
    }

 */
    GUI gui;
    gui.init();
    gui.show();
    Board board;
    Game game /*(board)*/;
    game.start();
    game.printWidth();

    return a.exec();
}
