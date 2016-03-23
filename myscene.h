#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QTimerEvent>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QVector>

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MyScene(QObject *parent = 0);

private:
    const int timerInterval = 5;
    QVector<QGraphicsItem*> forDelete;

    virtual void timerEvent(QTimerEvent *);
    virtual void keyPressEvent(QKeyEvent *event);

signals:
    void timeIsOver(qreal);
    void keyIsPress();

public slots:
    void deleteItem(QGraphicsItem *);
};

#endif // MYSCENE_H
