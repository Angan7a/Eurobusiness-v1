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
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");
        std::map<int, std::pair<int, int>> mapFields_ = board_->getMapFields();
        //for (auto i = 0; i < 40; i++)
          //  std::cout << mapFields_[i]. first << "   ->   " << mapFields_[i].second << std::endl;


    for (int i = 0; i < numberOfPlayers; i++)
    {
        vecPlayersPtr_.push_back(std::make_shared<Player>(static_cast<Color>(i), mapFields_));
    }

    for (auto player : vecPlayersPtr_)
    {
        auto field = board_->getField(0);
        //player->setPos(roll_->throwIt(player),roll_->throwIt(player));
        //player->setLocation(0);
        scene_->addItem(player.get());
        //player->setFlag(QGraphicsItem::ItemIsFocusable);
        //player->setFocus();
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
        int numberField = roll_->throwIt(player);
        player->moveLocation(numberField);
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
