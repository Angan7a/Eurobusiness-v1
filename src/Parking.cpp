#include "Parking.hpp"

Parking::Parking(const std::string name) :
    Field(name)
{}
void Parking::doOn(PlayerPtr player)
{
    player->reduceMoney(400);
}

void Parking::draw(int x, int y)
{

}
