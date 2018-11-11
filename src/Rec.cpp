#include "Rect.hpp"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>

QGraphicsRectItem * RectBasic::draw(int x, int y)
{
    QGraphicsRectItem * r = new QGraphicsRectItem();
    r->setRect(x, y, 100, 50);
    return r;

}

WithSmallRectUp::WithSmallRectUp(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectUp::draw(int x, int y)
{
    QGraphicsRectItem * rect = recBasic_->draw(x, y);
    QGraphicsRectItem * smallRect = new QGraphicsRectItem(rect);
    smallRect->setRect(x, y, 100, 10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    smallRect->setBrush(brush);
    return rect;
}

WithSmallRectRight::WithSmallRectRight(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectRight::draw(int x, int y)
{
    QGraphicsRectItem * rect = recBasic_->draw(x, y);
    QGraphicsRectItem * smallRect = new QGraphicsRectItem(rect);
    smallRect->setRect(x + 90, y, 10, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    smallRect->setBrush(brush);
    return rect;
}

WithSmallRectDown::WithSmallRectDown(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectDown::draw(int x, int y)
{
    QGraphicsRectItem * rect = recBasic_->draw(x, y);
    QGraphicsRectItem * smallRect = new QGraphicsRectItem(rect);
    smallRect->setRect(x, y+40, 100, 10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    smallRect->setBrush(brush);
    return rect;
}

WithSmallRectLeft::WithSmallRectLeft(std::shared_ptr<RectInterface> recBasic) :
    recBasic_(recBasic)
{}

QGraphicsRectItem * WithSmallRectLeft::draw(int x, int y)
{
    QGraphicsRectItem * rect = recBasic_->draw(x, y);
    QGraphicsRectItem * smallRect = new QGraphicsRectItem(rect);
    smallRect->setRect(x, y, 10, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::blue);
    smallRect->setBrush(brush);
    return rect;
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
    text->setPos(x+8, y+20);
    return rect;
}
