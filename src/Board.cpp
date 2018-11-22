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

Board::Board(QTimer *, const std::string & fileName) :
    fields_(40)
{
    json j = readFile(fileName);
    setCards(j);
    setFieldToCards(j);
}

std::map<int, std::pair<int, int>> Board::getMapFields() const
{
    return mapFields_;
}

void Board::movePlayer1(PlayerPtr player, int fieldToReach)
{
    player->moveLocation(fieldToReach);
}

void Board::go1(PlayerPtr player)
{
    int nextPos = player->getLocation()+1;
    //player->setLocation(nextPos, getField(nextPos)->x(), getField(nextPos)->y() );
}

FieldPtr Board::getField(const unsigned int numberOfField) const noexcept
{
    int n = numberOfField%40;
    return fields_.at(n);
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
        scene->addItem(fields_.at(j)->drawRectBottom(lenX, lenY));
        std::pair<int, int> xy = std::make_pair(lenX, lenY);
        mapFields_[j++] = xy;
        lenX -= x;
    }
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j)->drawRectLeft(lenX, lenY));
        std::pair<int, int> xy = std::make_pair(lenX, lenY);
        mapFields_[j++] = xy;
        lenY -= y;
    }
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j)->drawRectTop(lenX, lenY));
        std::pair<int, int> xy = std::make_pair(lenX, lenY);
        mapFields_[j++] = xy;
        lenX += x;
    }
    for (int i = 0; i < 10; i++)
    {
        scene->addItem(fields_.at(j)->drawRectRight(lenX, lenY));
        std::pair<int, int> xy = std::make_pair(lenX, lenY);
        mapFields_[j++] = xy;
        lenY += y;
    }
    scene->addItem(redCards_.get());
    scene->addItem(blueCards_.get());
    return scene;
}
