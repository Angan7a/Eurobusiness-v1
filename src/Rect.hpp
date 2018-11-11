#pragma once

#include <QGraphicsRectItem>
#include <memory>

class RectInterface
{
public:
    virtual QGraphicsRectItem * draw(int x, int y) = 0;
};


class RectBasic : public RectInterface
{
 public:
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectUp : public RectInterface
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectUp(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectRight : public RectInterface
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectRight(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectDown : public RectInterface
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectDown(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};

class WithSmallRectLeft : public RectInterface
{
    std::shared_ptr<RectInterface> recBasic_;
public:
    WithSmallRectLeft(std::shared_ptr<RectInterface> recBasic);
    QGraphicsRectItem * draw(int x, int y) override;
};
