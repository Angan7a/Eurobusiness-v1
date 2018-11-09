#include "Eurobusiness.hpp"
#include <stdexcept>
#include <iostream>
//#include <QGraphicsTextItem>

Eurobusiness::Eurobusiness(int numberOfPlayers) : numberOfRounds(0)//, QWidget *parent) : numberOfRounds(0)
{
 //   setFixedSize(1024,768);
  //  scene = new QGraphicsScene();
  //  scene->setSceneRect(0,0,1024,768);
  //  setScene(scene);
    roll_ = std::make_shared<Roll>();
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");
    for (int i = 0; i < numberOfPlayers; i++)
    {
        vecPlayersPtr_.push_back(std::make_shared<Player>(static_cast<Color>(i)));
    }
    drawBoard();
}

void Eurobusiness::drawBoard()
{
    int x = 100;
    int lenX = 10*100;
    int y = 40;
    int lenY = 10*40;
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        lenX -= x;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        lenY -= y;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        lenX += x;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        lenY += y;
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
