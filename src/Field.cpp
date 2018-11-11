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

QGraphicsRectItem *Field::drawRectBottom(int x, int y)
{
    return rect_->draw(x, y);
}

QGraphicsRectItem *Field::drawRectLeft(int x, int y)
{
    return rect_->draw(x, y);
}

QGraphicsRectItem *Field::drawRectTop(int x, int y)
{
    return rect_->draw(x, y);
}

QGraphicsRectItem *Field::drawRectRight(int x, int y)
{
    return rect_->draw(x, y);
}
