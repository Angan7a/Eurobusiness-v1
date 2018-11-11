#pragma once

#include "Field.hpp"
#include "Player.hpp"

class Parking : public Field
{
public:
    Parking(const std::string name);
    void doOn(PlayerPtr player) override;
};
