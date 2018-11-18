#include <gtest/gtest.h>
#include "../src/Player.hpp"
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

TEST_F(PlayerTests, setLocationTo12ShouldMoveThePlayerToField12)
{
    player.changeLocation(12);
    ASSERT_EQ(12,player.getLocation());
}

TEST_F(PlayerTests, setLocationTo40ShouldMoveThePlayerToField0)
{
    player.changeLocation(40);
    ASSERT_EQ(0,player.getLocation());
}

TEST_F(PlayerTests, check_if_player_pass_start_his_money_increased)
{
    player.changeLocation(40);
    ASSERT_EQ(3400,player.getMoney());
}

TEST_F(PlayerTests, check_if_player_go_to_prison_and_invoke_addMoney_then_his_money_dont_increased)
{
    player.setState(std::make_shared<InPrison>());
    player.addMoney(30);
    ASSERT_EQ(3000,player.getMoney());
}

TEST_F(PlayerTests, check_if_player_move_left)
{
    std::shared_ptr<Player> player1 = std::make_shared<Player>(Color::RED);
    player1->setPos(100, 50);
    QSignalSpy spy(player1->getTimer(), SIGNAL(timeout()));
    player1->setLocation(1, 60, 50);
    int t = 100;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(60, player1->x());
    ASSERT_EQ(50, player1->y());
}

TEST_F(PlayerTests, check_if_player_move_right)
{
    std::shared_ptr<Player> player1 = std::make_shared<Player>(Color::RED);
    player1->setPos(100, 50);
    QSignalSpy spy(player1->getTimer(), SIGNAL(timeout()));
    player1->setLocation(1, 110, 50);
    int t = 100;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(110, player1->x());
    ASSERT_EQ(50, player1->y());
}

TEST_F(PlayerTests, check_if_player_move_dwon)
{
    std::shared_ptr<Player> player1 = std::make_shared<Player>(Color::RED);
    player1->setPos(100, 50);
    QSignalSpy spy(player1->getTimer(), SIGNAL(timeout()));
    player1->setLocation(1, 100, 60);
    int t = 100;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(100, player1->x());
    ASSERT_EQ(60, player1->y());
}

TEST_F(PlayerTests, check_if_player_move_up)
{
    std::shared_ptr<Player> player1 = std::make_shared<Player>(Color::RED);
    player1->setPos(100, 50);
    QSignalSpy spy(player1->getTimer(), SIGNAL(timeout()));
    player1->setLocation(1, 100, 40);
    int t = 100;
    while(t--)
        spy.wait(1);
    ASSERT_EQ(100, player1->x());
    ASSERT_EQ(40, player1->y());
}
