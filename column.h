#ifndef COLUMN_H
#define COLUMN_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Column : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Column(int type, int width, int height);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int type;
    const qreal v = -0.08;
    qreal width;
    qreal height;

signals:
    void deleteItem(QGraphicsItem *);

public slots:
    void updatePos(qreal);
};

#endif // COLUMN_H
