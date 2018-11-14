#include "Cards.hpp"
#include <QBrush>

Cards::Cards(CardsColor color, json dataPacked, int x, int y) :
    color_(color)
{
    for (auto it = dataPacked.begin(); it != dataPacked.end(); it++)
        collectionCards_.at(stoi(it.key())) = it.value();
    setRect(0, 0, 150, 250);
    setPos(x, y);
    QBrush brush;
    brush.setStyle(Qt::Dense7Pattern);
    brush.setColor(getQtColor());
    setBrush(brush);
}

Qt::GlobalColor Cards::getQtColor()
{
    if (color_ == CardsColor::RED) return Qt::red;
    return Qt::blue;
}

CardsColor Cards::getColor() const
{
    return color_;
}

oneCard Cards::getOneCard(const int number) const
{
    return collectionCards_.at(number);
}

void Cards::doOn(std::shared_ptr<Player>)
{

}
//===================
CardsI::CardsI(std::shared_ptr<Cards> cards, const std::string & name) :
    Field(name),
    cards_(cards)
{}

void CardsI::doOn(std::shared_ptr<Player>)
{

}

