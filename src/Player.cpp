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
}

void Player::move(int xField, QTimer * timer)
{
    setPos(x()-5, y());
    if (x() >= xField)
        delete timer;
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

void Player::changeLocation(const int location)
{
    state_->increaseNumberOfRounds();
    location_ += state_->action(location);
    if (location_ >= 40)
    {
        money_ += 400;
        location_ %= 40;
    }
}

void Player::setLocation(const int location, int xField, int yField)
{
    if (location == 0)
    {
        setPos(xField + getFactor(), yField + 35);
    } else
    {
        location_ = location;
        QTimer * timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move(xField, timer)));
        timer->start(50);
    }
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

bool Player::doYouWantBuyThisProperty() const
{
    std::cout << "Do you want buy this property?" << std::endl;
    bool answer;
    std::cin >> answer;
    return answer;
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
