#include "City.hpp"
#include "StateCity.hpp"
#include "Rect.hpp"

City::City(const std::string & city, const std::string & country, int purchasePrice, int priceStampNoBuilding, int priceStampOneHouse, int priceStampTwoHouses) :
    Property(city, purchasePrice),
    country_(country),
    priceStampNoBuilding_(priceStampNoBuilding),
    priceStampOneHouse_(priceStampOneHouse),
    priceStampTwoHouses_(priceStampTwoHouses)
{
    state_ = std::make_shared<YouCanBuy>();
}

QGraphicsRectItem *City::drawRectBottom(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectUp>(std::make_shared<RectBasic>());
    return rect_->draw(x, y);
}

QGraphicsRectItem *City::drawRectLeft(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectRight>(std::make_shared<RectBasic>());
    return rect_->draw(x, y);
}

QGraphicsRectItem *City::drawRectTop(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectDown>(std::make_shared<RectBasic>());
    return rect_->draw(x, y);
}

QGraphicsRectItem *City::drawRectRight(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectLeft>(std::make_shared<RectBasic>());
    return rect_->draw(x, y);
}
