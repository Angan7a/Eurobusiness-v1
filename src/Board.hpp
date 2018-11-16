#pragma once
#include <array>
#include <vector>
#include "Field.hpp"
#include "Cards.hpp"
#include "Property.hpp"
#include "WaterSupplyNetwork.hpp"
#include <memory>
#include "json.hpp"
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>

using FieldPtr = std::shared_ptr<Field>;
using PropertyPtr = std::shared_ptr<Property>;   
using json = nlohmann::json;

class Board : public QObject
{
    Q_OBJECT
private:
    std::vector<FieldPtr> fields_;
    std::shared_ptr<Cards> redCards_;   
    std::shared_ptr<Cards> blueCards_;   
    std::array<PropertyPtr, 28> properties_;
    QTimer * timer_;
    PlayerPtr player_;
    int numberFieldToReach_;
public:
    Board(const std::string & fileName = "../files/configData.json");
    ~Board() = default;
    Board(const Board&) = delete;
    Board(Board&&) = delete;
    Board& operator=(const Board&) = delete;
    Board& operator=(Board&&) = delete;

    json readFile(const std::string & fileName);
    void setCards(json dataPacked);
    void setFieldToCards(const json & dataFields);
    FieldPtr getField(const unsigned int numberOfField) const noexcept;
    FieldPtr factoryFields(const std::string & name);
    QGraphicsScene * drawFields();
    void movePlayer(PlayerPtr player, int numberFieldToGo);
public slots:
    void go();
};

