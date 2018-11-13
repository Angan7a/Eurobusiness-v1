#include "Roll.hpp"

Roll::Roll(std::shared_ptr<DiceI> dice, int fieldPrison, int xPrison, int yPrison) :
    fieldPrison_(fieldPrison),
    xPrison_(xPrison),
    yPrison_(yPrison)
{
    dice_ = dice;
}

int Roll::throwIt(PlayerPtr player)
{
    int r1 = dice_->throwIt();
    int r2 = dice_->throwIt();
    if (r1 == r2)
    {
        int r3 = dice_->throwIt();
        int r4 = dice_->throwIt();
        if (r3 == r4)
        {
            player->setState(std::shared_ptr<InPrison>());
            player->setLocation(fieldPrison_, xPrison_, yPrison_);
            return 0;
        }
        return r1 + r2 + r3 + r4;
    }
    return r1 + r2;
}
