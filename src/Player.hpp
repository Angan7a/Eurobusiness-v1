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
    int xToReach_, yToReach_, step_ = 1;
    std::map<int, std::pair<int, int>> mapFields_;
public:
    Qt::GlobalColor getQtColor();
    Player()= delete;
    Player(const Player &) = delete;
    Player(Player &&) = delete;
    virtual ~Player() = default;
    Player & operator=(const Player &) = delete;
    Player & operator=(Player &&) = delete;

    Player(Color c, std::map<int, std::pair<int, int>> mapFields = {std::make_pair(2, std::make_pair(2, 2))}, QGraphicsItem * parent = 0);

    Color getColor() const;
    virtual int getMoney() const;
    void reduceMoney(int price);
    int addMoney(int price);
    int getLocation() const;
    void moveLocation(const int location);
    void setLocation(const int locationToReach);
    void addProperty(const std::shared_ptr<Property> & property);
    void setState(StatePlayerPtr state);
    void canLeavePrison();
    int getXToReach_() {return xToReach_;}
    int getYToReach_() {return yToReach_;}
public slots:
    void move();
    QTimer * getTimer() { return timer; }
signals:
    void changePosToGo(PlayerPtr);
};
