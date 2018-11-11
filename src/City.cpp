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
    rect_ = std::make_shared<RectBasic>();
    rect_ = std::make_shared<Text>(rect_, city+"-"+country_);
    state_ = std::make_shared<YouCanBuy>();
}

QGraphicsRectItem *City::drawRectBottom(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectUp>(rect_);
    return rect_->draw(x, y);
}

QGraphicsRectItem *City::drawRectLeft(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectRight>(rect_);
    return rect_->draw(x, y);
}

QGraphicsRectItem *City::drawRectTop(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectDown>(rect_);
    return rect_->draw(x, y);
}

QGraphicsRectItem *City::drawRectRight(int x, int y)
{
    rect_ = std::make_shared<WithSmallRectLeft>(rect_);
    return rect_->draw(x, y);
}
