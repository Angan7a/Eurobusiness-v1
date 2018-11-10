#include "Eurobusiness.hpp"
#include <stdexcept>
#include <iostream>
#include <QGraphicsRectItem>
//#include <QGraphicsTextItem>

Eurobusiness::Eurobusiness(int numberOfPlayers) : numberOfRounds(0)//, QWidget *parent) : numberOfRounds(0)
{
    board_ = std::make_shared<Board>();
    setFixedSize(1200,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene_ = board_->drawFields();
    //scene_->setSceneRect(0,0,1024,768);
    //setScene(scene_);/home/a/Eurobusiness-v1/files
    setScene(scene_);
  //  board_->
    roll_ = std::make_shared<Roll>();
    if (numberOfPlayers < 2 || numberOfPlayers > 5) throw std::out_of_range("The number of players should between 2 - 5");
    for (int i = 0; i < numberOfPlayers; i++)
    {
        vecPlayersPtr_.push_back(std::make_shared<Player>(static_cast<Color>(i)));
    }
    //drawBoard();
}

void Eurobusiness::drawBoard()
{
    int x = 80;
    int lenX = 10*x;
    int y = 50;
    int lenY = 10*y;
    std::vector<QGraphicsRectItem *> r1;
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(lenX,lenY, x, y);
        r1.push_back(r);
        lenX -= x;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(lenX,lenY,x,y);
        r1.push_back(r);
        lenY -= y;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(lenX,lenY,x,y);
        r1.push_back(r);
        lenX += x;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << lenX << ", " << lenY << std::endl;
        QGraphicsRectItem * r = new QGraphicsRectItem();
        r->setRect(lenX,lenY,x,y);
        r1.push_back(r);
        lenY += y;
    }
    for (auto r : r1)
    {
        scene_->addItem(r);
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
