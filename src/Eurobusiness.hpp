#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Roll.hpp"
#include <vector>
#include <memory>
//#include <QGraphicsView>
//#include <QGraphicsScene>

using VecPlayersPtr = std::vector<std::shared_ptr<Player>>;

class Eurobusiness //: public QGraphicsView
{
    std::shared_ptr<Board> board_;
    VecPlayersPtr vecPlayersPtr_;
    std::shared_ptr<Roll> roll_;
    int numberOfRounds;
 //   QGraphicsScene * scene_;
public:
    Eurobusiness(int numberOfPlayers);//, QWidget * parent=NULL);

    VecPlayersPtr getAllPlayers() const;
    void playOneRound();
    void play();
    void drawBoard();
};
