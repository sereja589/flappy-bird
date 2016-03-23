#include "column.h"

Column::Column(int type, int width,  int height) : type(type), width(width), height(height)
{

}

QRectF Column::boundingRect() const
{
    if (type)
        return QRectF(-width, -height, width, height);
    return QRectF(-width, 0, width, height);
}

void Column::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::red));
    QPen pn(Qt::red);
    pn.setWidth(0);
    painter->setPen(pn);
    painter->drawRect(boundingRect());
}

void Column::updatePos(qreal t)
{
    qreal newX = pos().x() + v * t;
    qreal newY = pos().y();
    if (newX + boundingRect().width() < 0)
    {
        emit deleteItem(this);
    }
    else
    {
        setPos(newX, newY);
    }
}
