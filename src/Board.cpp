#include "Board.hpp"
#include "City.hpp"
#include "Cards.hpp"
#include "Railway.hpp"
#include "Parking.hpp"
#include "OrdinaryCard.hpp"
#include "YouGoToPrison.hpp"
#include <string>
#include <fstream>
#include <QGraphicsItem>
#include <iostream>

Board::Board(QTimer * timer, const std::string & fileName) :
    fields_(40)
{
    json j = readFile(fileName);
    setCards(j);
    setFieldToCards(j);
    timer_ = timer;
    connect(timer_, SIGNAL(timeout()), this, SLOT(go()));
}

void Board::movePlayer(PlayerPtr player, int numberFieldToReach)
{
    numberFieldToReach_ = numberFieldToReach;
    FieldPtr fieldNext = fields_.at(player->getLocation()+1);
    XToReach_ = fieldNext->x();
    YToReach_ = fieldNext->y();
   // player->setXYWherePlayerGo(field->x(), field->y());
    player_ = player;
    timer_->start(1);
    //player_->move();
}

void Board::movePlayer1(PlayerPtr player, int fieldToReach)
{
    player_= player;
    int nextPos = player_->getLocation()+1;
    player_->setLocation(player->getLocation(), fields_.at(nextPos)->x(), fields_.at(nextPos)->y() );
    numberFieldToReach_ = fieldToReach;
    connect(timer_, SIGNAL(timeout()), this, SLOT(go1()));
    timer_->start(1);
}

void Board::go1()
{
    if (player_->getLocation() == numberFieldToReach_)
    {
        timer_->stop();
    } else if (player_->getLocation()+1 == numberFieldToReach_)
    {
        int nextPos = player_->getLocation()+1;
        FieldPtr nextField = fields_.at(nextPos);
        if (nextField->x() < player_->x() && player_->x() < nextField->x()+100)
        {
            player_->setLocation(nextPos, fields_.at(nextPos)->x(), fields_.at(nextPos)->y() );
        }
    } else
    {
        int nextPos = player_->getLocation()+1;
        FieldPtr nextField = fields_.at(nextPos);
        if (nextField->x() < player_->x() && player_->x() < nextField->x()+100)
        {
            player_->setLocation(nextPos, fields_.at(nextPos+1)->x(), fields_.at(nextPos+1)->y() );
        }
    }
}

void Board::go()
{
    if (XToReach_== player_->x() && YToReach_ == player_->y())
       timer_->stop();
    else 
    {
        if (player_->getLocation() != numberFieldToReach_)
        {
            int locX = getField(player_->getLocation()+1)->x(); 
            int locY = getField(player_->getLocation()+1)->y(); 
            if (locX < player_->x() && player_->x() < locX+100)
            {
                player_->moveLocation(1);
                if (player_->getLocation() != numberFieldToReach_)
                {
                    locX = getField(player_->getLocation()+1)->x(); 
                    locY = getField(player_->getLocation()+1)->y(); 
                    XToReach_ = locX;
                    YToReach_ = locY;
                }
            }
        }
        if (player_->x() > XToReach_)
            player_->descriseX();
        else if (player_->x() < XToReach_)
            player_->increaseX();
        else if (player_->y() > YToReach_)
            player_->descriseY();
        else if (player_->y() < YToReach_)
            player_->increaseY();
    //}
    }
}

FieldPtr Board::getField(const unsigned int numberOfField) const noexcept
{
    return fields_.at(numberOfField);
}

FieldPtr Board::factoryFields(const std::string & name)
{
    auto pos = name.find("-");
    if (pos != std::string::npos)
        return std::make_shared<City>(name.substr(pos + 2), name.substr(0, pos - 1));
    else if (name.find("Koleje") != std::string::npos)
        return std::make_shared<Railway>(name);
    else if (name.find("Parking") != std::string::npos)
        return std::make_shared<Parking>(name);
    else if (name.find("Idziesz do") != std::string::npos)
        return std::make_shared<YouGoToPrison>(name);
    else if (name == "Szansa (czerwona)")
        return std::make_shared<CardsI>(redCards_, name);
    else if (name == "Szansa (niebieska)")
        return std::make_shared<CardsI>(blueCards_, name);
    else if (name == "Sieć wodociągów")
        return std::make_shared<WaterSupplyNetwork>(name, 120);
    return std::make_shared<OrdinaryCard>(name);
}

json Board::readFile(const std::string & fileName)
{
    std::ifstream file(fileName);
    json j;
    if (file)
    {
        file >> j;
        file.close();
    }
    return j;
}

void Board::setCards(json dataPacked)
{
    redCards_ = std::make_shared<Cards>(CardsColor::RED, dataPacked["cards"]["red"], 200 , 200);
    blueCards_ = std::make_shared<Cards>(CardsColor::BLUE, dataPacked["cards"]["blue"], 800, 200);
}

void Board::setFieldToCards(const json & dataPacked)
{
    for (auto it = dataPacked["fields"].begin(); it != dataPacked["fields"].end(); it++)
        fields_.at(stoi(it.key())) = factoryFields(it.value());
}

QGraphicsScene * Board::drawFields()
{
    QGraphicsScene * scene = new QGraphicsScene();
    int x = 100;
    int lenX = 10*x;
    int y = 50;
    int lenY = 10*y;
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j++)->drawRectBottom(lenX, lenY));
        lenX -= x;
    }
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j++)->drawRectLeft(lenX, lenY));
        lenY -= y;
    }
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j++)->drawRectTop(lenX, lenY));
        lenX += x;
    }
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j++)->drawRectRight(lenX, lenY));
        lenY += y;
    }
    scene->addItem(redCards_.get());
    scene->addItem(blueCards_.get());
    return scene;
}
