#include <gtest/gtest.h>
#include "../src/Player.hpp"
#include "../src/Board.hpp"
#include <QSignalSpy>
#include <QtTest/QtTest>


struct PlayerTests : public::testing::Test
{
    Player player{Color::BLUE};
};

TEST_F(PlayerTests, checkIfPlayerIsCreatedWithDefaultParameters)
{
    ASSERT_EQ(Color::BLUE, player.getColor());
    ASSERT_EQ(3000,player.getMoney());
    ASSERT_EQ(0,player.getLocation());
}

TEST_F(PlayerTests, check_if_player_can_move_1_field)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
    player->moveLocation(1);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(915, player->x());
    ASSERT_EQ(535, player->y());
}

TEST_F(PlayerTests, check_if_player_can_move_6_times_1_field)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t, i = 7;
    while (i--)
    {
        t = 123;
        while(t--)
            spy.wait(1);
        player->moveLocation(1);
    }
    ASSERT_EQ(415, player->x());
}

TEST_F(PlayerTests, check_if_player_can_move_2_fields)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 323;
    player->moveLocation(2);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(535, player->y());
    ASSERT_EQ(815, player->x());
}

TEST_F(PlayerTests, check_if_player_can_move_3_times_2_fields)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t, i = 3;
    while (i--)
    {
        t = 223;
        player->moveLocation(2);
        while(t--)
        spy.wait(1);
    }
    ASSERT_EQ(535, player->y());
    ASSERT_EQ(415, player->x());
}

TEST_F(PlayerTests, check_if_player_can_move_5_times_1_field)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 123;
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


TEST_F(PlayerTests, check_if_player_can_move_12_fields)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 1323;
    board.movePlayer1(player, 12);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(15, player->x());
    ASSERT_EQ(435, player->y());
}

TEST_F(PlayerTests, check_if_player_can_move_21_fields)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 2123;
    player->moveLocation(21);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(115, player->x());
    ASSERT_EQ(5, player->y());
}

TEST_F(PlayerTests, check_if_player_can_move_41_fields)
{
    QTimer *timer = new QTimer();
    Board board(timer);
    board.drawFields();
    PlayerPtr player = std::make_shared<Player>(Color::RED, board.getMapFields());
    
    QSignalSpy spy(timer, SIGNAL(timeout()));
    int t = 4123;
    player->moveLocation(41);
    while(t--)
        spy.wait(1);
    ASSERT_EQ(915, player->x());
    ASSERT_EQ(535, player->y());
}

TEST_F(PlayerTests, check_if_player_pass_start_his_money_increased)
{
    player.moveLocation(40);
    ASSERT_EQ(3400,player.getMoney());
}


TEST_F(PlayerTests, check_if_player_go_to_prison_and_invoke_addMoney_then_his_money_dont_increased)
{
    player.setState(std::make_shared<InPrison>());
    player.addMoney(30);
    ASSERT_EQ(3000,player.getMoney());
}

