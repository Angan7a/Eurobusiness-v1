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

std::shared_ptr<RectInterface> Field::getRect() const
{
    return rect_;
}

QGraphicsRectItem * Field::draw(int x, int y, QGraphicsRectItem * baseRec)
{
    QGraphicsRectItem * r = new QGraphicsRectItem();
    r->setRect(x, y, 100, 50);
    QGraphicsTextItem * t = new QGraphicsTextItem(r);
/*    QGraphicsRectItem * rSmall = new QGraphicsRectItem(r);
    rSmall->setRect(x,y,10,10);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    rSmall->setBrush(brush);*/
    t->setPlainText(QString::fromStdString(getName()));
    t->setDefaultTextColor(Qt::blue);
    t->setPos(x+12,y+15);
    t->setFont(QFont("Times",8));
    return r;
}
