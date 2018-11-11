#pragma once
#include <memory>
#include <string>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include "Rect.hpp"


class Player;
using PlayerPtr = std::shared_ptr<Player>;

class Field
{
    std::string name_;
protected:
    std::shared_ptr<RectInterface> rect_;
public:
    Field() = delete;
    Field(const Field &) = delete;
    Field(Field &&) = delete;
    Field& operator=(const Field &) = delete;
    Field& operator=(Field &&) = delete;
    Field(const std::string & name);
    virtual ~Field() = default;
    
    virtual void doOn(PlayerPtr player) = 0;
    std::string getName() const;
    virtual QGraphicsRectItem * drawRectBottom(int x, int y);
    virtual QGraphicsRectItem * drawRectLeft(int x, int y);
    virtual QGraphicsRectItem * drawRectTop(int x, int y);
    virtual QGraphicsRectItem * drawRectRight(int x, int y);

    std::shared_ptr<RectInterface> getRect() const;
    //virtual QGraphicsRectItem * draw(int x, int y) = 0;
    virtual QGraphicsRectItem * draw(int x, int y, QGraphicsRectItem * baseRec = nullptr);
    QGraphicsRectItem * draw1(int x, int y)
    {
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(x, y, 100, 50);
        QGraphicsTextItem * t = new QGraphicsTextItem(r);
        QGraphicsRectItem * rSmall = new QGraphicsRectItem(r);
        rSmall->setRect(x,y,10,10);

        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        rSmall->setBrush(brush);
        t->setPlainText(QString::fromStdString(getName()));
        t->setDefaultTextColor(Qt::blue);
        t->setPos(x+12,y+15);
        t->setFont(QFont("Times",8));
        return r;
    }
};
