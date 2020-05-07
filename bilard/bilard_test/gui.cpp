#include "gui.h"
#include "Board.h"
#include "Ball.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QString>
#include <QGraphicsSimpleTextItem>
#include <vector>
#include <QTime>
#include <QFont>
#include <QPen>
#include <QPointF>

using namespace std;

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
       int d = 2*getGUIR(balls->at(0)->getRadius());

       for (int i = 0; i < 16; i++) {
           int x = getGUIX(balls->at(i)->getX());
           int y = getGUIY(balls->at(i)->getY());
           int r = d/2;
           
           QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
           ellipse->setRect(x, y, d, d);
           ellipse->setBrush(getQTColor(balls->at(i)->getColor()));
           scene->addItem(ellipse);
           guiBalls.push_back(ellipse);
           if (i > 8) {
               /* QGraphicsRectItem* strippedRect = new QGraphicsRectItem();
               strippedRect->setRect(x+(r-r*sqrt(3))/2, y-r/4, r*sqrt(3), r/2);
               strippedRect->setBrush(Qt::white);
               scene->addItem(strippedRect); */
           }
           printBall(i, x + r, y + r);
       }

}
void GUI::refresh(){
    int d = 2 * getGUIR(balls->at(0)->getRadius());
    for (int i = 0; i < 16; i++) {
        Ball* b = balls->at(i);
        if (b->hasChanged()) {
            QGraphicsEllipseItem* ellipse = guiBalls.at(i);
            int dx = balls->at(i)->getDX();
            int dy = balls->at(i)->getDY();
            ellipse->setX(dx);
            ellipse->setY(dy);
        }
    }
}
void GUI::delay(int ms)
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void GUI::show(){
    view->show();
}
void GUI::show2() {
    view->repaint();
}
void GUI::setBoard(Board* board)
{
    this->board = board;
}
void GUI::setBalls(std::vector<Ball*>* balls) {
    this->balls = balls;
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
void GUI::printBall(int i, int x, int y)
{
    int r = getGUIR(balls->at(i)->getRadius());
    std::string s = std::to_string(i);
    QString qs = QString::fromStdString(s);
    QGraphicsSimpleTextItem* text = new QGraphicsSimpleTextItem();
    text->setText(qs);
    text->setPos(x-(r/2), y-(r/2));

    QFont font;
    font.setPixelSize(r);
    font.setBold(1);
    text->setFont(font);
    QPen pen;
    if (i == 8) pen.setBrush(Qt::white);
    text->setPen(pen);
    scene->addItem(text);
}
void GUI::setScreenHeight(int screenHeight)
{
    this->screenHeight = screenHeight;
}

void GUI::setScreenWidth(int screenWidth)
{
    this->screenWidth = screenWidth;
}

int GUI::getGUIX(int x)
{
    return x*screenWidth / getBoard()->getWidth();
}
int GUI::getGUIY(int y)
{
    return screenHeight - (y*screenHeight / getBoard()->getHeight());
}
int GUI::getGUIR(int r)
{
    return r * screenWidth / getBoard()->getWidth();
    /* balls->at(0)->getRadius */
}
void GUI::hideBalls()
{

}
void GUI::refreshBalls()
{

}
QBrush GUI::getQTColor(Color color)
{
    QBrush tab[9] = { Qt::white, Qt::yellow, Qt::blue, Qt::red, Qt::darkYellow, Qt::darkMagenta, Qt::green, Qt::darkRed, Qt::black };
    return tab[color];
}
