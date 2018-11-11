#include "Property.hpp"
#include <iostream>

Property::Property(const std::string & name, int price) :
    Field(name),
    purchasePrice_(price),
    owner_(nullptr),
    state_(std::make_shared<YouCanBuy>())
{}

Property::Property(const std::string & name, int price, VecPlayersPtr vecPlayersPtr) :
    Property(name, price)
{
    vecPlayersPtr_ = vecPlayersPtr;
}

int Property::getPurchasePrice() const
{
    return purchasePrice_;
}

void Property::doOn(std::shared_ptr<Player> player)
{
    if (owner_ == nullptr)
    {
        if (player->doYouWantBuyThisProperty())
        {
            owner_ = player;
            player->reduceMoney(purchasePrice_);
        } else 
        {
          //  state_ = std::make_shared<Auction>(this);
          //  PlayerPtr newOwner = whoWantBuyThisProperty();
          //  newOwner->reduceMoney(purchasePrice_);
        }
    } else if (player != owner_) 
    {
        player->reduceMoney(owner_->addMoney(getPriceStamp()));
    }
}

std::shared_ptr<Player> Property::getOwner() const
{
    return owner_;
}

void Property::setOwner(std::shared_ptr<Player> player)
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

PlayerPtr Property::whoWantBuyThisProperty()
{
    std::cout << "Auction of property?" << std::endl;
    for (auto player : vecPlayersPtr_)
    {
        if (player->doYouWantBuyThisProperty()) return player;
    }
}

QGraphicsRectItem * Property::draw(int x, int y, QGraphicsRectItem * basicRec)
{
    basicRec = Field::draw(x, y);//new QGraphicsRectItem();
  /*  QGraphicsRectItem * rSmall = new QGraphicsRectItem(basicRec);
    rSmall->setRect(x,y,100,10);
    std::cout << basicRec->x() <<std::endl;
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    rSmall->setBrush(brush);*/
    return basicRec;
}
