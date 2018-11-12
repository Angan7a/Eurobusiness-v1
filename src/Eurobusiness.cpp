#include "Eurobusiness.hpp"
#include <stdexcept>
#include <iostream>
#include <QGraphicsRectItem>
//#include <QGraphicsTextItem>

Eurobusiness::Eurobusiness(int numberOfPlayers) : numberOfRounds(0)//, QWidget *parent) : numberOfRounds(0)
{
    board_ = std::make_shared<Board>();
    setFixedSize(1200,600);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_ = board_->drawFields();
    setScene(scene_);
    roll_ = std::make_shared<Roll>();
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");
    for (int i = 0; i < numberOfPlayers; i++)
    {
        vecPlayersPtr_.push_back(std::make_shared<Player>(static_cast<Color>(i)));
    }
    int a = 15;
    for (auto player : vecPlayersPtr_)
    {
        player->setRect(0, 0, 10, 10);
        player->setPos(board_->getField(0)->x() + a, board_->getField(0)->y() + 35);
        a += 15;
        scene_->addItem(player.get());
    }
}

VecPlayersPtr Eurobusiness::getAllPlayers() const
{
    return vecPlayersPtr_;
}

void Eurobusiness::playOneRound()
{
    numberOfRounds++;
    for (auto player : vecPlayersPtr_)
    {
        int roll = roll_->throwIt(player);
        player->changeLocation(roll);
        player->canLeavePrison();
        //FieldPtr field = board_->getField(player->getLocation());
       // field->doOn(player);
    }
}

void Eurobusiness::play()
{
    playOneRound();
}
