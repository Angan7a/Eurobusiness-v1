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
    QGraphicsRectItem * qRect_;
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
    virtual QGraphicsRectItem * setQRect(int x, int y);
    int x() const;
    int y() const;
};
