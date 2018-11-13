#include "Eurobusiness.hpp"
#include <stdexcept>
#include <iostream>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QKeyEvent>

Eurobusiness::Eurobusiness(int numberOfPlayers) : numberOfRounds(0)//, QWidget *parent) : numberOfRounds(0)
{
    board_ = std::make_shared<Board>();
    //setFixedSize(1200,600);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_ = board_->drawFields();
    //setScene(scene_);
    roll_ = std::make_shared<Roll>();
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");

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

QGraphicsScene * Eurobusiness::getScene() const
{
    return scene_;
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
        int location = player->getLocation();
        auto field = board_->getField(location);
        player->setLocation(location, field->x(), field->y());
        player->canLeavePrison();
        //FieldPtr field = board_->getField(player->getLocation());
       // field->doOn(player);
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
