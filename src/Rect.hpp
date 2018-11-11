#pragma once

#include <QGraphicsRectItem>
#include <memory>

class RectInterface
{
public:
    virtual QGraphicsRectItem * draw(int x, int y) = 0;
    QGraphicsRectItem * addRect(int x, int y, int w, int h, QGraphicsRectItem * rect, Qt::GlobalColor color);
};

//=============================

class RectBasic : public RectInterface
{
 public:
    QGraphicsRectItem * draw(int x, int y) override;
};

//=============================

class WithSmallRect : public RectInterface
{
    virtual QGraphicsRectItem * draw(int x, int y) = 0;
};

class WithSmallRectUp : public WithSmallRect
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectUp(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectRight : public WithSmallRect
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectRight(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectDown : public WithSmallRect
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectDown(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectLeft : public WithSmallRect
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectLeft(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class Text : public WithSmallRect
{
    std::shared_ptr<RectInterface> recBasic_;
    std::string name_;
public:
    Text(std::shared_ptr<RectInterface> recBasic, const std::string & name);
    QGraphicsRectItem * draw(int x, int y) override;
};
