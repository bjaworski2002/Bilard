#pragma once
#include <QObject>
#include "gui.h"
class GUI;
class GuiBall
{
	QGraphicsEllipseItem* ellipse;
	QGraphicsRectItem* strippedRect;
	QGraphicsSimpleTextItem* ballNumber;
	QBrush color;
public:

	GuiBall(int x, int y, int r, int number);

	void addNumber(int number, int x, int y, int r);
	void setColor(QBrush &color);
	void addItems(GUI* gui);


};
