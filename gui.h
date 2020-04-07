#ifndef GUI_H
#define GUI_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>

class GUI
{
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
public:
    GUI();
    void init();
    void refresh();
    void show();
};

#endif // GUI_H
