#include "Player.hpp"
#include <algorithm>
#include <iostream>

Player::Player(Color c, QGraphicsItem * parent)
        : QGraphicsEllipseItem(parent),
        color_(c),
        money_(3000),
        location_(0),
        state_(std::make_shared<Free>())
{
    setRect(0, 0, 10, 10);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(getQtColor());
    setBrush(brush);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Player::setLocationToReach(int location)
{
    locationToReach_ = location;
}

void Player::setLocation(const int location, int xField, int yField)
{
    if (location == 0)
    {
        setPos(xField, yField);
    } else
    {
        location_ = location;
        xToReach_ = xField; //+ getFactor();
        ToReach_ = yField;// + 35;
        timer->start(1);  //call method move()
    }
}

void Player::moveLocation(const int location)
{
    location_ += state_->action(location);
    if (location_ >= 40)
    {
        money_ += 400;
        location_ %= 40;
    }
}

void Player::move()
{
    if (xToReach_ == x() && ToReach_ == y())
    {
            timer->stop();
        if (location_ != locationToReach_)
            emit changePosToGo(shared_from_this());
    }
    else if (x() > xToReach_)
        setPos(x()-step_, y());
    else if (x() < xToReach_)
        setPos(x()+step_, y());
    else if (y() > ToReach_)
        setPos(x(), y()-step_);
    else if (y() < ToReach_)
        setPos(x(), y()+step_);
}

Color Player::getColor() const
{
    return color_;
}

int Player::getMoney() const
{
    return money_;
}

int Player::getLocation() const
{
    return location_;
}

void Player::addProperty(const std::shared_ptr<Property> & property)
{
    properties_.push_back(property);
}

void Player::reduceMoney(int price)
{
    money_ -= price;
}

int Player::addMoney(int price)
{
    int priceToReduce = state_->action(price);
    money_ += priceToReduce;
    return priceToReduce;
}

void Player::setState(StatePlayerPtr state)
{
    state_ = state;
}

void Player::canLeavePrison()
{
    if (state_->canPlayerLeavePrison()) 
        state_ = std::make_shared<Free>();
}

Qt::GlobalColor Player::getQtColor()
{
    if (color_ == Color::RED) return Qt::red;
    if (color_ == Color::BLUE) return Qt::blue;
    if (color_ == Color::GREEN) return Qt::green;
    if (color_ == Color::YELLOW) return Qt::yellow;
    return Qt::black;
}

int Player::getFactor() const
{
    int a = 15;
    if (color_ == Color::RED) return a;
    if (color_ == Color::BLUE) return 2*a;
    if (color_ == Color::GREEN) return 3*a;
    if (color_ == Color::YELLOW) return 4*a;
    return 5*a;
}
