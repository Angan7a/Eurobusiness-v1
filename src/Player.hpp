#pragma once

#include <string>
#include "Property.hpp"
#include "StatePlayer.hpp"
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

class Property;
using PropertiesPtr = std::vector<std::shared_ptr<Property>>;
using StatePlayerPtr = std::shared_ptr<StatePlayer>;

enum class Color: unsigned char{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    BLACK
};

class Player : public QObject, public QGraphicsEllipseItem{
    Q_OBJECT

    Color color_;
    int money_;
    int location_;
    PropertiesPtr properties_;
    StatePlayerPtr state_;
    int getFactor() const;
    QTimer * timer;
    int x_, y_, tempNumberField_, tempX_, tempY_, step_ = 5;
    void increaseX();
    void descriseX();
    void increaseY();
    void descriseY();
    Qt::GlobalColor getQtColor();
public:
    Player()= delete;
    Player(const Player &) = delete;
    Player(Player &&) = delete;
    virtual ~Player() = default;
    Player & operator=(const Player &) = delete;
    Player & operator=(Player &&) = delete;

    Player(Color c, QGraphicsItem * parent = 0);

    Color getColor() const;
    virtual int getMoney() const;
    void reduceMoney(int price);
    int addMoney(int price);
    int getLocation() const;
    void changeLocation(const int location);
    void setLocation(const int location, int xField, int yField);
    void addProperty(const std::shared_ptr<Property> & property);
    void setState(StatePlayerPtr state);
    void canLeavePrison();
    void setXYWherePlayerGo(int x, int y);
public slots:
    void move();
};
