#include "Property.hpp"
#include <iostream>

Property::Property(const std::string & name, int price) :
    Field(name),
    purchasePrice_(price),
    owner_(nullptr),
    state_(std::make_shared<YouCanBuy>())
{}

int Property::getPurchasePrice() const
{
    return purchasePrice_;
}

void Property::doOn(PlayerPtr player)
{
    if (owner_ == nullptr)
    {
        owner_ = player;
        player->reduceMoney(purchasePrice_);
    } else 
    {
        player->reduceMoney(owner_->addMoney(getPriceStamp()));
    }
}

PlayerPtr Property::getOwner() const
{
    return owner_;
}

void Property::setOwner(PlayerPtr player)
{
    owner_ = player;
}

int Property::getPriceStamp() const
{
    return state_->getPriceStamp();
}

void Property::setState(StatePtr state)
{
    state_ = state;
}

