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

class Player : public QObject, public QGraphicsEllipseItem, public std::enable_shared_from_this<Player>{
    Q_OBJECT

    Color color_;
    int money_;
    int location_;
    PropertiesPtr properties_;
    StatePlayerPtr state_;
    int getFactor() const;
    QTimer * timer;
    int locationToReach_;
    int xToReach_, ToReach_, step_ = 1;
public:
    Qt::GlobalColor getQtColor();
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
    void moveLocation(const int location);
    void setLocation(const int location, int xField, int yField);
    void addProperty(const std::shared_ptr<Property> & property);
    void setState(StatePlayerPtr state);
    void canLeavePrison();
    int getxToReach_() {return xToReach_;}
    int getToReach_() {return ToReach_;}
    void setLocationToReach(int location);
public slots:
    void move();
    QTimer * getTimer() { return timer; }
signals:
    void changePosToGo(PlayerPtr);
};
