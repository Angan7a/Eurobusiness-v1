#pragma once

#include "Property.hpp"

class City : public Property
{
    std::string country_;
    int priceStampNoBuilding_;
    int priceStampOneHouse_;
    int priceStampTwoHouses_;
public:
    City(const std::string & city, const std::string & country, int purchasePrice = 300, int priceStampNoBuilding = 70, int priceStampOneHouse = 300, int priceStampTwoHouses = 500);
    QGraphicsRectItem * drawRectBottom(int x, int y) override;
    QGraphicsRectItem * drawRectLeft(int x, int y) override;
    QGraphicsRectItem * drawRectTop(int x, int y) override;
    QGraphicsRectItem * drawRectRight(int x, int y) override;
};
