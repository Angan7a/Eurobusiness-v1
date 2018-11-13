#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "Roll.hpp"
#include <vector>
#include <memory>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QApplication>

using VecPlayersPtr = std::vector<std::shared_ptr<Player>>;

class Eurobusiness : public QObject, public QGraphicsRectItem
{
//    Q_OBJECT

    std::shared_ptr<Board> board_;
    VecPlayersPtr vecPlayersPtr_;
    std::shared_ptr<Roll> roll_;
    int numberOfRounds;
    QGraphicsScene * scene_;
public:
    Eurobusiness(int numberOfPlayers);//, QWidget * parent=NULL);

    VecPlayersPtr getAllPlayers() const;
    void playOneRound();
    void play();
    void keyPressEvent(QKeyEvent *event); 
    QGraphicsScene * getScene() const;
};
