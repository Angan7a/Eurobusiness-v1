#pragma once

#include "Dice.hpp"
#include "Player.hpp"


class Roll
{
    int fieldPrison_;
    int xPrison_;
    int yPrison_;
    std::shared_ptr<DiceI> dice_;
public:
    Roll(std::shared_ptr<DiceI> dice = std::make_shared<Dice>(), int fieldPrison_ = 10, int xPrison = 20, int yPrison = 20);
    int throwIt(PlayerPtr player);
};
