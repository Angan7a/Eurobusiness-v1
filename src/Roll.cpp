#include "Roll.hpp"
#include <QGraphicsEllipseItem>

Roll::Roll(std::shared_ptr<DiceI> dice, int fieldPrison, int xPrison, int yPrison) :
    fieldPrison_(fieldPrison),
    xPrison_(xPrison),
    yPrison_(yPrison)
{
    dice_ = dice;
    setRect(0, 0, 100, 50);
    QGraphicsRectItem * rect1 = new QGraphicsRectItem(10, 10, 40, 40, this);
    QGraphicsRectItem * rect2 = new QGraphicsRectItem(10, 10, 40, 40, this);
    text1_ = new QGraphicsTextItem(rect1);
    text2_ = new QGraphicsTextItem(rect2);
    text1_->setPos(3, 3);
    text2_->setPos(3, 3);
}

int Roll::throwIt(PlayerPtr player)
{
    int r1 = dice_->throwIt();
    int r2 = dice_->throwIt();
    text1_->setPlainText(QString::number(r1));
    text2_->setPlainText(QString::number(r2));
    if (r1 == r2)
    {
        int r3 = dice_->throwIt();
        int r4 = dice_->throwIt();
        text1_->setPlainText(QString::number(r3));
        text2_->setPlainText(QString::number(r4));
        if (r3 == r4)
        {
            player->setLocation(fieldPrison_);
            player->setState(std::make_shared<InPrison>());
            return 0;
        }
        return r1 + r2 + r3 + r4;
    }
    return r1 + r2;
}
