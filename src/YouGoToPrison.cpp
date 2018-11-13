#include "YouGoToPrison.hpp"

YouGoToPrison::YouGoToPrison(const std::string & name, int prisonField, int xPrison, int yPrison) : 
    Field(name),
    prisonField_(prisonField),
    xPrison_(xPrison),
    yPrison_(yPrison)
{}

void YouGoToPrison::doOn(PlayerPtr player)
{
    player->setLocation(prisonField_, xPrison_, yPrison_);
}
