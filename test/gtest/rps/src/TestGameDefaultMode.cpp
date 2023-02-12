
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
          humainStrategy(std::make_shared<rps::MockHumainStrategy>()),
          aGame(std::make_shared<rps::Game>()) {}

   protected:
    std::shared_ptr<rps::MockRockStrategy> rockStrategy;
    std::shared_ptr<rps::MockHumainStrategy> humainStrategy;
    std::shared_ptr<rps::Game> aGame;
};

TEST_F(GameDefaultTest, TestRockStrategyVersusHumainStrategy_PAPER) {
    auto mPlayer = std::make_shared<rps::MachinePlayer>();
    auto hPlayer = std::make_shared<rps::HumainPlayer>();

    mPlayer->setStrategy(rockStrategy);
    hPlayer->setStrategy(humainStrategy);

    EXPECT_CALL(*rockStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::ROCK));

    EXPECT_CALL(*humainStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::PAPER));

    auto mChoice = mPlayer->getRPSChoice();
    EXPECT_EQ(mChoice, rps::RPS_CHOICE::ROCK);
    auto hChoice = hPlayer->getRPSChoice();
    EXPECT_EQ(hChoice, rps::RPS_CHOICE::PAPER);

    auto res = aGame->getRoundResult(static_cast<int>(hChoice),
                                     static_cast<int>(mChoice));
    EXPECT_EQ(res, rps::ROUND_RESULT::WIN);
}

TEST_F(GameDefaultTest, TestRockStrategyVersusHumainStrategy_ROCK) {
    auto mPlayer = std::make_shared<rps::MachinePlayer>();
    auto hPlayer = std::make_shared<rps::HumainPlayer>();

    mPlayer->setStrategy(rockStrategy);
    hPlayer->setStrategy(humainStrategy);

    EXPECT_CALL(*rockStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::ROCK));

    EXPECT_CALL(*humainStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::ROCK));

    auto res = aGame->getRoundResult(static_cast<int>(hPlayer->getRPSChoice()),
                                     static_cast<int>(mPlayer->getRPSChoice()));
    EXPECT_EQ(res, rps::ROUND_RESULT::DRAW);
}

TEST_F(GameDefaultTest, TestRockStrategyVersusHumainStrategy_SCISSORS) {
    auto mPlayer = std::make_shared<rps::MachinePlayer>();
    auto hPlayer = std::make_shared<rps::HumainPlayer>();

    mPlayer->setStrategy(rockStrategy);
    hPlayer->setStrategy(humainStrategy);

    EXPECT_CALL(*rockStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::ROCK));

    EXPECT_CALL(*humainStrategy, createRPSChoice())
        .WillOnce(::testing::Return(rps::RPS_CHOICE::SCISSORS));

    auto res = aGame->getRoundResult(static_cast<int>(hPlayer->getRPSChoice()),
                                     static_cast<int>(mPlayer->getRPSChoice()));
    EXPECT_EQ(res, rps::ROUND_RESULT::LOSE);
}
