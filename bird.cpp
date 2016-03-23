#include "bird.h"
#include <iostream>
#include <QtMath>
#include <QRgb>

Bird::Bird(qreal width, qreal height, QColor clr = Qt::white) : width(width), height(height)
{
    img = QImage("bird.png");
    a = aBegin;
    v = vBegin;
    if (v < 0)
    {
        setRotation(-5);
        rotate = false;
    }
    else
    {
        setRotation(10);
        rotate = true;
    }
}

QRectF Bird::boundingRect() const
{
    return QRectF(-width / 2, -height / 2, width, height);
}

void Bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect(), img);
}

void Bird::updatePos(qreal t)
{
    qreal newX = scenePos().x();
    qreal newY = scenePos().y() + v * t;
    QRectF sceneRect = scene()->sceneRect();
    QPointF birdTopLeft = mapToScene(boundingRect().topLeft());
    QRectF birdRect(birdTopLeft, boundingRect().size());

    if (sceneRect.top() > birdRect.top())
    {
        emit reStartGame();
        return;
    }
    if (sceneRect.bottom() < birdRect.bottom())
    {
        emit reStartGame();
        return;
    }

    setPos(newX, newY);
    v += a * t;

    if (v < 0 && rotate)
    {
        setRotation(-5);
        rotate = false;
    }
    if (v > 0 && !rotate)
    {
        setRotation(10);
        rotate = true;
    }

    if (collidingItems().size())
    {
        emit reStartGame();
    }
}

void Bird::keyPress()
{
    v = vBegin;
}

qreal Bird::distColor(QColor *c1, QColor *c2)
{
    int d1 = c1->red() - c2->red();
    int d2 = c1->green() - c2->green();
    int d3 = c1->blue() - c2->blue();
    qreal d = qSqrt(d1 * d1 + d2 * d2 + d3 * d3);
    return d;
}
