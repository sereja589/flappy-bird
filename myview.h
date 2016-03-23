#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QResizeEvent>

class MyView : public QGraphicsView
{

public:
    MyView(QWidget *parent = 0);
    MyView(QGraphicsScene *scene = 0, QWidget *parent = 0);

private:
    void resizeEvent(QResizeEvent *);
};

#endif // MYVIEW_H
