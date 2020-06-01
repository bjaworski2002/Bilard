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

GuiBall::GuiBall(int x, int y, int r, int number, Ball* ball, GUI* gui) {
    
    this->ball = ball;
    int d = 2 * r;
    ellipse = new QGraphicsEllipseItem();
    ellipse->setRect(x, y, d, d);
    if (number > 8) {
        strippedRect = new QGraphicsRectItem();
        strippedRect->setRect(x+((2*r-(r*sqrt(3)))/2), y+(r/2), r*sqrt(3), r);
        strippedRect->setBrush(Qt::white);    
    }
    else {
        strippedRect = NULL;
    }
    addNumber(number, x, y, r, gui);
}
void GuiBall::addNumber(int number, int x, int y, int r, GUI* gui)
{
    std::string s = std::to_string(number);
    QString qs = QString::fromStdString(s);
    ballNumber = new QGraphicsSimpleTextItem();
    ballNumber->setText(qs);
    setPosNumber(x, y, r, number);

    QFont font;
    font.setPixelSize(r);
    font.setBold(1);
    ballNumber->setFont(font);
    QPen pen;
    if (number == 8) pen.setBrush(Qt::white);
    ballNumber->setPen(pen);
}

void GuiBall::setColor(QBrush &color)
{
    this->color = color;
    ellipse->setBrush(color);
}

void GuiBall::addItems(GUI* gui)
{
    gui->addItem(ellipse);
    if (strippedRect != NULL) {
        gui->addItem(strippedRect);
    }
    gui->addItem(ballNumber);
}

void GuiBall::refresh()
{
    ellipse->setX(ball->getDX());
    ellipse->setY(ball->getDY()); 

   setPosNumber(ball->getX() - ball->getRadius()*2/3, ball->getY() - ball->getRadius()*2/3, ball->getRadius(), ball->getNumber());
   // ballNumber->setX(ball->getX());
   // ballNumber->setY(ball->getY());
}

void GuiBall::setX(int x)
{
    ball->setX(x);
}
void GuiBall::setY(int y)
{
    ball->setY(y);
}
void GuiBall::setPosNumber(int x, int y, int r, int number)
{
    if (number < 10) {
        ballNumber->setPos(x + r - (r / 5), y + r - (r * 3 / 5));
    }
    else {
        ballNumber->setPos(x + r - (r * 4 / 5), y + r - (r * 3 / 5));
    }
}
int GuiBall::getX()
{
    return ball->getX();
}
int GuiBall::getY()
{
    return ball->getY();
}