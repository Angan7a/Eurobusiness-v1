#include "Field.hpp"

Field::Field(const std::string & name) :
    name_(name)
{
    rect_ = std::make_shared<RectBasic>();
}

std::string Field::getName() const
{
    return name_;
}

QGraphicsRectItem * Field::getRect() const
{
    return qRect_;
}

QGraphicsRectItem * Field::setQRect(int x, int y)
{
    rect_ = std::make_shared<Text>(std::make_shared<RectBasic>(), getName());
    qRect_ = rect_->draw(x, y);
    return qRect_;
}

int Field::x() const
{
   return qRect_->x();
}

int Field::y() const
{
   return qRect_->y();
}

QGraphicsRectItem *Field::drawRectBottom(int x, int y)
{
    return setQRect(x, y);
}

QGraphicsRectItem *Field::drawRectLeft(int x, int y)
{
    return setQRect(x, y);
}

QGraphicsRectItem *Field::drawRectTop(int x, int y)
{
    return setQRect(x, y);
}

QGraphicsRectItem *Field::drawRectRight(int x, int y)
{
    return setQRect(x, y);
}
