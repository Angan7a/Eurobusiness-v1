#include "Eurobusiness.hpp"
#include <stdexcept>
#include <iostream>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QKeyEvent>

Eurobusiness::Eurobusiness(int numberOfPlayers, std::shared_ptr<DiceI> dice) : numberOfRounds(0)//, QWidget *parent) : numberOfRounds(0)
{
    board_ = std::make_shared<Board>();
    setFixedSize(1200,600);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_ = board_->drawFields();
    setScene(scene_);
    roll_ = std::make_shared<Roll>(dice, 10, 20, 20);
    roll_->setPos(600, 500);
    scene_->addItem(roll_.get());
   // if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");

    for (int i = 0; i < numberOfPlayers; i++)
    {
        vecPlayersPtr_.push_back(std::make_shared<Player>(static_cast<Color>(i)));
    }

    for (auto player : vecPlayersPtr_)
    {
        auto field = board_->getField(0);
        player->setLocation(0, field->x(), field->y());
        scene_->addItem(player.get());
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
    }
}

VecPlayersPtr Eurobusiness::getAllPlayers() const
{
    return vecPlayersPtr_;
}

void Eurobusiness::playOneRound()
{
    numberOfRounds++;
   static int i = 0;
    for (auto player : vecPlayersPtr_)
    {
        int numberField = 1; //roll_->throwIt(player);
      //  board_->movePlayer1(player, numberField);
        i++;
        player->setLocation(3,board_->getField(i)->x(), board_->getField(i)->y());
        player->canLeavePrison();
        auto field = board_->getField(numberField);
        field->doOn(player);
    }
}

void Eurobusiness::play()
{
    playOneRound();
}

void Eurobusiness::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        playOneRound();
    }
}
