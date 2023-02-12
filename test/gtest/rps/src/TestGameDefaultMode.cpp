
#include "Game.hpp"
#include "HumainPlayer.hpp"
#include "MachinePlayer.hpp"
#include "MockHumainStrategy.hpp"
#include "MockRockStrategy.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class GameDefaultTest : public ::testing::Test {
   public:
    GameDefaultTest()
        : rockStrategy(std::make_shared<rps::MockRockStrategy>()),
          humainStrategy(std::make_shared<rps::MockHumainStrategy>()) {}

   protected:
    std::shared_ptr<rps::MockRockStrategy> rockStrategy;
    std::shared_ptr<rps::MockHumainStrategy> humainStrategy;
};

TEST_F(GameDefaultTest, Test1) {
    auto mPlayer = std::make_shared<rps::MachinePlayer>();
    auto hPlayer = std::make_shared<rps::HumainPlayer>();

    mPlayer->setStrategy(rockStrategy);
    hPlayer->setStrategy(humainStrategy);

    EXPECT_CALL(*rockStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::PAPER));

    EXPECT_CALL(*humainStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::PAPER));

    EXPECT_EQ(mPlayer->getRPSChoice(), rps::RPS_CHOICE::PAPER);
    // hPlayer->getRPSChoice();
}