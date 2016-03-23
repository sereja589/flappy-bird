#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QObject>
#include <QColor>

#include "bird.h"
#include "myview.h"
#include "myscene.h"
#include "column.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game();

protected:
    virtual void timerEvent(QTimerEvent *);

private:
    const QColor viewBackground = QColor(0, 200, 255);
    int timerId;
    MyScene *scene;
    MyView *view;
    const int timerInterval = 2500;
    void initialize();

public slots:
    void reStartGame();
};

#endif // GAME_H
