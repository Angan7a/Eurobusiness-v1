#pragma once
#include <memory>
#include <string>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

class Player;
using PlayerPtr = std::shared_ptr<Player>;

class Field
{
    std::string name_;
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
    //virtual QGraphicsRectItem * draw(int x, int y) = 0;
    virtual void draw(int x, int y) = 0;
    QGraphicsRectItem * draw1(int x, int y)
    {
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(x, y, 100, 50);
        QGraphicsTextItem * t = new QGraphicsTextItem(r);
        static int a=0;
        a++;
        t->setPlainText(QString("Score:")+QString::number(a)); // Score: 0
        t->setDefaultTextColor(Qt::blue);
        t->setPos(x,y);
       // t->setFont(QFont("times",16));
        return r;
    }
};
