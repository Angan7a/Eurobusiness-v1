#pragma once
#include "json.hpp"
#include <array>
#include "Field.hpp"
#include <QGraphicsRectItem>

using json = nlohmann::json;
using oneCard = std::string;

enum class CardsColor
{
    RED,
    BLUE
};

class Cards : public QGraphicsRectItem
{
    CardsColor color_;
    std::array<oneCard, 16> collectionCards_;
public:
    Cards() = delete;
    Cards(const Cards &) = delete;
    Cards(Cards &&) = delete;
    Cards & operator=(const Cards &) = delete;
    Cards & operator=(Cards &&) = delete;
    ~Cards() = default;
    Cards(CardsColor color, json dataPacked, int x, int y);

    oneCard getOneCard(const int number) const;
    CardsColor getColor() const;
    void doOn(std::shared_ptr<Player> player);
    Qt::GlobalColor getQtColor();
};

//=========================
class CardsI : public Field
{
    std::shared_ptr<Cards> cards_;
public:
    CardsI(std::shared_ptr<Cards>, const std::string & name);

    void doOn(std::shared_ptr<Player> player) override;
};
