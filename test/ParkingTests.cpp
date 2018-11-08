#include <gtest/gtest.h>
#include "Parking.hpp"

struct ParkingTests : public ::testing::Test
{
    std::shared_ptr<Field> parking = std::make_shared<Parking>("Parking strzezony");
};

TEST_F(ParkingTests, check_if_name_is_set_to_parking_strzezony)
{
    ASSERT_EQ("Parking strzezony", parking->getName());
}

TEST_F(ParkingTests, check_if_after_stamp_on_parking_charge_player_400)
{
    PlayerPtr player = std::make_shared<Player>(Color::RED);
    parking->doOn(player);
    ASSERT_EQ(2600, player->getMoney());
}

