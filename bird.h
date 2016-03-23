#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsItem>
#include <QPainter>
#include <QImage>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QColor>

class Bird : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Bird(qreal width, qreal height, QColor clr);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    bool rotate;
    qreal width;
    qreal height;
    QImage img;
    const qreal vBegin = -0.2, aBegin = 0.0007;
    qreal a;
    qreal v;

    qreal distColor(QColor *c1,QColor *c2);

signals:
    void reStartGame();

public slots:
    void updatePos(qreal);
    void keyPress();

};

#endif // BIRD_H
