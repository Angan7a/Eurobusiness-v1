#include <gtest/gtest.h>
#include "../src/Eurobusiness.hpp"
#include "../test/mock/DiceMock.hpp"
#include <memory>
#include <QApplication>

using namespace ::testing;

struct EurobusinessTests : public ::testing::Test
{
  };

TEST_F(EurobusinessTests, check_if_create_eurobusiness_with_1_player_throw)
{
    ASSERT_ANY_THROW(Eurobusiness(1));
}

TEST_F(EurobusinessTests, created_eurobusiness_with_4_players_then_check_if_number_of_players_is_the_same)
{
    Eurobusiness euro(4);
    ASSERT_EQ(4u, (euro.getAllPlayers()).size() );
}

TEST_F(EurobusinessTests, created_eurobusiness_with_4_players_then_check_if_1_players_has_RED_color)
{
    Eurobusiness euro(4);
    ASSERT_EQ(Color::RED, (euro.getAllPlayers()).at(0)->getColor() );
}
/*
TEST_F(EurobusinessTests, create_player_in_prison_made_3_round_and_check_if_player_is_free_and_can_charge_money)
{
    std::shared_ptr<DiceMock> mock = std::make_shared<DiceMock>();
    Eurobusiness euro(2, mock);
    (euro.getAllPlayers()).at(1)->setState(std::make_shared<InPrison>());
    ASSERT_EQ(3000, (euro.getAllPlayers()).at(1)->getMoney() );
    //1 round
    EXPECT_CALL(* mock, throwIt())
        .Times(4)
        .WillOnce(Return(1))
        .WillOnce(Return(2))
        .WillOnce(Return(1))
        .WillOnce(Return(2));
    euro.playOneRound();
    ASSERT_EQ(3001, (euro.getAllPlayers()).at(1)->getMoney() );
    //2 round
    EXPECT_CALL(* mock, throwIt())
        .Times(4)
        .WillOnce(Return(1))
        .WillOnce(Return(2))
        .WillOnce(Return(1))
        .WillOnce(Return(2));
    euro.playOneRound();
    (euro.getAllPlayers()).at(1)->addMoney(30);
    ASSERT_EQ(3002, (euro.getAllPlayers()).at(1)->getMoney() );
    //3 round
    EXPECT_CALL(* mock, throwIt())
        .Times(4)
        .WillOnce(Return(1))
        .WillOnce(Return(2))
        .WillOnce(Return(1))
        .WillOnce(Return(2));
    euro.playOneRound();
    (euro.getAllPlayers()).at(1)->addMoney(5300);
    ASSERT_EQ(3030, (euro.getAllPlayers()).at(1)->getMoney() );
}*/
/*
TEST_F(EurobusinessTests, Mock)
{
    std::shared_ptr<DiceMock> mock = std::make_shared<DiceMock>();
    Eurobusiness euro(2, mock);
    EXPECT_CALL(* mock, throwIt())
        .Times(4)
        .WillOnce(Return(1))
        .WillOnce(Return(2))
        .WillOnce(Return(3))
        .WillOnce(Return(2));
    euro.playOneRound();
    ASSERT_EQ(3, (euro.getAllPlayers()).at(0)->getLocation() );
    ASSERT_EQ(5, (euro.getAllPlayers()).at(1)->getLocation() );
}*/
