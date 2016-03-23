#include "myscene.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    startTimer(timerInterval);
}

void MyScene::timerEvent(QTimerEvent *ev)
{
    for (auto it = forDelete.begin(); it != forDelete.end(); ++it)
    {
        removeItem(*it);
        delete (*it) ;
    }
    forDelete.clear();

    emit timeIsOver(timerInterval);
}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
        emit keyIsPress();
}

void MyScene::deleteItem(QGraphicsItem *it)
{
    forDelete.push_back(it);
}
