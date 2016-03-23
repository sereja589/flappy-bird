#include "myview.h"
#include <iostream>

MyView::MyView(QWidget *parent) : QGraphicsView(parent)
{

}

MyView::MyView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene, parent)
{

}

void MyView::resizeEvent(QResizeEvent *)
{
    fitInView(sceneRect());
}
