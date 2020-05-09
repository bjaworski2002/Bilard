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

GuiBall::GuiBall(int x, int y, int r, int number) {
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
    addNumber(number, x + r, y + r, r);
}
void GuiBall::addNumber(int number, int x, int y, int r)
{
    std::string s = std::to_string(number);
    QString qs = QString::fromStdString(s);
    ballNumber = new QGraphicsSimpleTextItem();
    ballNumber->setText(qs);
    if (number < 10) {
        ballNumber->setPos(x - (r / 5), y - (r * 3 / 5));
    }
    else {
        ballNumber->setPos(x - (r * 4 / 5), y - (r * 3 / 5));
    }

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
