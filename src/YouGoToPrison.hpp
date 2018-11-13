#pragma once
#include "Field.hpp"
#include "Player.hpp"

class YouGoToPrison : public Field
{
    int prisonField_; 
    int xPrison_;
    int yPrison_;
public:
    YouGoToPrison(const std::string & name, int prisonField = 10, int xPrison = 200, int yPrison = 200);
    void doOn(PlayerPtr player);
};
