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
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
    player->setPos(1015, 535);
    board.movePlayer1(player, 1);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(915, player->x());
    ASSERT_EQ(535, player->y());
}

TEST_F(BoardTest, check_if_player_can_move_6_times_1_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
    player->setPos(1015, 1015);
    board.movePlayer1(player, 1);
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 1);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 1);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 1);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 1);
    t = 123;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 1);
    t = 123;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(415, player->x());
}

TEST_F(BoardTest, check_if_player_can_move_2_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 323;
    player->setPos(1015, 535);
    board.movePlayer1(player, 2);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(535, player->y());
    ASSERT_EQ(815, player->x());
}

TEST_F(BoardTest, check_if_player_can_move_3_times_2_fields_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 323;
    player->setPos(1015, 535);
    board.movePlayer1(player, 2);
    t = 223;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 2);
    t = 223;
    while(t--)
        spy.wait(1);
    board.movePlayer1(player, 2);
    t = 223;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(535, player->y());
    ASSERT_EQ(415, player->x());
}

TEST_F(BoardTest, check_if_player_can_move_5_times_1_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
    player->setPos(1015, 535);
    int i = 5;
    while(i--)
    {
        board.movePlayer1(player, 1);
        t = 123;
        while(t--)
            spy.wait(1);
    }
    ASSERT_EQ(515, player->x());
    ASSERT_EQ(535, player->y());
}


TEST_F(BoardTest, check_if_player_can_move_12_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 1323;
    player->setPos(1015, 535);
    board.movePlayer1(player, 12);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(15, player->x());
    ASSERT_EQ(435, player->y());
}

TEST_F(BoardTest, check_if_player_can_move_21_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 2123;
    player->setPos(1015, 535);
    board.movePlayer1(player, 21);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(115, player->x());
    ASSERT_EQ(5, player->y());
}

TEST_F(BoardTest, check_if_player_can_move_41_field_____1)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 4123;
    player->setPos(1015, 535);
    board.movePlayer1(player, 41);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(915, player->x());
    ASSERT_EQ(535, player->y());
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
   // ASSERT_EQ("iPłacisz na budowę szpitala 415 $.", board.getBlueCard());
}

TEST_F(BoardTest, check_method_setFieldToCards_if_correct_set_pointer_Cards_to_field)
{
    json j = board.readFile("../files/configData.json");
    board.setCards(j);
    board.setFieldToCards(j);
    ASSERT_EQ("Zobowiązany jesteś zmodernizować swoje miasto, płacisz za każdy dom 80 $,za każdy hotel 230 $", std::dynamic_pointer_cast<Cards>(board.getField(7))->getOneCard(0));
    ASSERT_EQ("iPłacisz na budowę szpitala 415 $.", std::dynamic_pointer_cast<Cards>(board.getField(2))->getOneCard(0));
}
*/
