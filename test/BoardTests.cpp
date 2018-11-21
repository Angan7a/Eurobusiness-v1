#include <gtest/gtest.h>
#include "../src/Board.hpp"
#include "../src/Field.hpp"
#include <memory>
#include <QSignalSpy>
#include <QtTest/QtTest>
#include <QTimer>
#include <iostream>

struct BoardTest : public ::testing::Test
{
    Board board;
};

TEST_F(BoardTest, check_if_factoryFields_made_Property_Madrit)
{
    std::shared_ptr<Field> madrit = board.factoryFields("Espania - Madrit");
    system("pwd");
    ASSERT_EQ("Madrit", madrit->getName());
}

TEST_F(BoardTest, check_if_factoryFields_made_Railway_West)
{
    std::shared_ptr<Field> railway = board.factoryFields("Koleje wschodnie");
    ASSERT_EQ("Koleje wschodnie", railway->getName());
}

TEST_F(BoardTest, check_if_factoryFields_made_OrdynaryCard)
{
    std::shared_ptr<Field> ordinaryCard = board.factoryFields("Start");
    ASSERT_EQ("Start", ordinaryCard->getName());
}

TEST_F(BoardTest, check_if_factoryFields_made_parking)
{
    std::shared_ptr<Field> parking = board.factoryFields("Parking");
    ASSERT_EQ("Parking", parking->getName());
}

TEST_F(BoardTest, check_if_player_can_move_1_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    board.drawFields();
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
    player->setPos(1000, 500);
    board.movePlayer1(player, 1);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(900, player->x());
    ASSERT_EQ(500, player->y());
}

TEST_F(BoardTest, check_if_player_can_move_6_times_1_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    board.drawFields();
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
    player->setPos(1000, 1000);
    board.movePlayer1(player, 1);
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 2);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 3);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 4);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 5);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 6);
    t = 123;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(400, player->x());
}

TEST_F(BoardTest, check_if_player_can_move_2_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    board.drawFields();
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 323;
    player->setPos(1000, 500);
    board.movePlayer1(player, 2);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(500, player->y());
    ASSERT_EQ(800, player->x());
}

TEST_F(BoardTest, check_if_player_can_move_12_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    board.drawFields();
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 1323;
    player->setPos(1000, 500);
    board.movePlayer1(player, 12);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(0, player->x());
    ASSERT_EQ(400, player->y());
}

TEST_F(BoardTest, check_if_player_can_move_21_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    board.drawFields();
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 2323;
    player->setPos(1000, 500);
    board.movePlayer1(player, 21);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(100, player->x());
    ASSERT_EQ(0, player->y());
}

TEST_F(BoardTest, check_if_player_can_move_41_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    board.drawFields();
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 4323;
    player->setPos(1000, 500);
    board.movePlayer1(player, 41);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(900, player->x());
    ASSERT_EQ(500, player->y());
}

/*
TEST_F(BoardTest, check_if_method_readFile_return_json_file)
{
    json j = board.readFile("../files/configData.json");
    ASSERT_EQ("aStart", j["fields"]["0"]);
}

TEST_F(BoardTest, check_method_setCards_if_correct_set_blue_and_red_cards)
{
    json j = board.readFile("../files/configData.json");
    board.setCards(j);
   // ASSERT_EQ("Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $", board.getRedCard());
   // ASSERT_EQ("iPłacisz na budowę szpitala 400 $.", board.getBlueCard());
}

TEST_F(BoardTest, check_method_setFieldToCards_if_correct_set_pointer_Cards_to_field)
{
    json j = board.readFile("../files/configData.json");
    board.setCards(j);
    board.setFieldToCards(j);
    ASSERT_EQ("Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $", std::dynamic_pointer_cast<Cards>(board.getField(7))->getOneCard(0));
    ASSERT_EQ("iPłacisz na budowę szpitala 400 $.", std::dynamic_pointer_cast<Cards>(board.getField(2))->getOneCard(0));
}
*/
