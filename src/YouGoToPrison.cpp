#include "YouGoToPrison.hpp"

YouGoToPrison::YouGoToPrison(const std::string & name, int prisonField) : 
    Field(name),
    prisonField_(prisonField)
{}

void YouGoToPrison::doOn(PlayerPtr player)
{
    player->setLocation(prisonField_);
}

void YouGoToPrison::draw(int x, int y)
{

}
