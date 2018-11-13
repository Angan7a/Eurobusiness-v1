#pragma once
#include "Field.hpp"
#include "Player.hpp"

class YouGoToPrison : public Field
{
    int prisonField_; 
    int xPrison_;
    int yPrison_;
public:
    YouGoToPrison(const std::string & name, int prisonField = 10, int xPrison = 12, int yPrison = 50);
    void doOn(PlayerPtr player);
};
