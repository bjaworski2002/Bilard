#include "gui.h"
#include "GuiBall.h"
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
       int r = getGUIR(balls->at(0)->getRadius());

       for (int i = 0; i < 16; i++) {
           int x = getGUIX(balls->at(i)->getX());
           int y = getGUIY(balls->at(i)->getY());

           GuiBall* guiBall = new GuiBall(x, y, r, i, balls->at(i), this);
           guiBall->setColor(getQTColor(balls->at(i)->getColor()));
           guiBall->addItems(this);
           guiBalls.push_back(guiBall);
           /* QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem();
           ellipse->setRect(x, y, d, d);
           ellipse->setBrush(getQTColor(balls->at(i)->getColor()));
           scene->addItem(ellipse);
           guiBalls.push_back(ellipse);
           if (i > 8) {
               QGraphicsRectItem* strippedRect = new QGraphicsRectItem();
               ellipse->setBrush(Qt::white);
               scene->addItem(ellipse);
               strippedRect->setRect(x+((2*r-(r*sqrt(3)))/2), y+(r/2), r*sqrt(3), r);
               strippedRect->setBrush(getQTColor(balls->at(i)->getColor()));
               scene->addItem(strippedRect);
           }
           addNumber(i, x + r, y + r); */
       }

}
void GUI::refresh(){
    int d = 2 * getGUIR(balls->at(0)->getRadius());
    for (int i = 0; i < 16; i++) {
        Ball* b = balls->at(i);
        if (b->hasChanged()) {
            GuiBall* guiBall = guiBalls.at(i);
            //int dx = balls->at(i)->getDX();
            //int dy = balls->at(i)->getDY();
            //print(dx);
            //print(dy);
            //guiBall->setX(x);
            //guiBall->setY(y);
            guiBall->refresh();
            //print(balls->at(i)->getX());
            //print(balls->at(i)->getY());
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
void GUI::addItem(QGraphicsItem* item)
{
    scene->addItem(item);
}
/* void GUI::addNumber(int i, int x, int y)
{
    int r = getGUIR(balls->at(i)->getRadius());
    std::string s = std::to_string(i);
    QString qs = QString::fromStdString(s);
    QGraphicsSimpleTextItem* ballNumber = new QGraphicsSimpleTextItem();
    ballNumber->setText(qs);
    if (i < 10) {
        ballNumber->setPos(x - (r / 5), y - (r*3 / 5));
    }
    else {
        ballNumber->setPos(x - (r*4 / 5), y - (r*3/5));
    }

    QFont font;
    font.setPixelSize(r);
    font.setBold(1);
    ballNumber->setFont(font);
    QPen pen;
    if (i == 8) pen.setBrush(Qt::white);
    ballNumber->setPen(pen);
    scene->addItem(ballNumber);
} */
void GUI::setScreenHeight(int screenHeight)
{
    this->screenHeight = screenHeight;
}

void GUI::setScreenWidth(int screenWidth)
{
    this->screenWidth = screenWidth;
}

int GUI::getGUIX(double x)
{
    /*print(x * screenWidth / getBoard()->getWidth());*/
    return x * screenWidth / getBoard()->getWidth();
}
int GUI::getGUIY(double y)
{
    return screenHeight - (y*screenHeight / getBoard()->getHeight());
}
int GUI::getGUIR(double r)
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
