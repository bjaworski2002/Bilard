#pragma once
#include <QObject>
#include "gui.h"
#include "Ball.h"

class GUI;
class GuiBall
{
	QGraphicsEllipseItem* ellipse;
	QGraphicsRectItem* strippedRect;
	QGraphicsSimpleTextItem* ballNumber;
	QBrush color;
	Ball* ball;

public:

	GuiBall(int x, int y, int r, int number, Ball* ball);

	void addNumber(int number, int x, int y, int r);
	void setColor(QBrush &color);
	void addItems(GUI* gui);
	void refresh();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();

};
