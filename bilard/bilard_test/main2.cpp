//#include <iostream>
//#include "game.h"
//#include "Board.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
//using namespace std;

int main(int argc, char* argv[])
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
}

/* int main()
{
//    Board board;
    Game game *//*(board)*//*;
    game.start();
//    game.printWidth();
    return 0;
} */
