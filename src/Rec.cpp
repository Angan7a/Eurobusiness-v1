#include "Rect.hpp"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>

QGraphicsRectItem * RectBasic::draw(int x, int y)
{
    QGraphicsRectItem * r = new QGraphicsRectItem();
    r->setRect(0, 0, 100, 50);
    r->setPos(x, y);
    return r;
}

QGraphicsRectItem * RectInterface::addRect(int x, int y, int w, int h, QGraphicsRectItem * rect, Qt::GlobalColor color)
{
    QGraphicsRectItem * smallRect = new QGraphicsRectItem(rect);
    smallRect->setRect(0, 0, w, h);
    smallRect->setPos(x, y);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    smallRect->setBrush(brush);
    return rect;
}

WithSmallRectUp::WithSmallRectUp(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectUp::draw(int x, int y)
{
    return addRect(0, 0, 100, 10, recBasic_->draw(x, y), Qt::red);
}

WithSmallRectRight::WithSmallRectRight(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectRight::draw(int x, int y)
{
    return addRect(90, 0, 10, 50, recBasic_->draw(x, y), Qt::blue);
}

WithSmallRectDown::WithSmallRectDown(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectDown::draw(int x, int y)
{
    return addRect(0, 40, 100, 10, recBasic_->draw(x, y), Qt::green);
}

WithSmallRectLeft::WithSmallRectLeft(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectLeft::draw(int x, int y)
{
    return addRect(0, 0, 10, 50, recBasic_->draw(x, y), Qt::yellow);
}

Text::Text(std::shared_ptr<RectInterface> recBasic, const std::string & name) :
    recBasic_(recBasic),
    name_(name)
{}

QGraphicsRectItem * Text::draw(int x, int y)
{
    QGraphicsRectItem * rect = recBasic_->draw(x, y);
    QGraphicsTextItem * text = new QGraphicsTextItem(rect);
    text->setPlainText(QString::fromStdString(name_));
    text->setFont(QFont("times",7));
    text->setPos(8, 20);
    return rect;
}
