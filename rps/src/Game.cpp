#include "Game.hpp"

#include <iostream>
#include <memory>

#include "HumainPlayer.hpp"
#include "MachinePlayer.hpp"
#include "UserStrategy.hpp"

namespace rps {

Game::Game()
    : mPlayer_(std::make_shared<MachinePlayer>()),
      hPlayer_(std::make_shared<HumainPlayer>()),
      gameDificulty_(std::make_shared<GameDificulty>()) {}

Game::~Game() {}

void Game::init() {
    mPlayer_->setStrategy(gameDificulty_->getGameStrategy(GAME_LEVEL::EASY));
    hPlayer_->setStrategy(std::make_shared<UserStrategy>());
}

ROUND_RESULT Game::getRoundResult(int hChoice, int mChoice) {
    std::cout << "hChoice := " << hChoice << ", mChoice := " << mChoice
              << std::endl;
    return gameReference_[hChoice][mChoice];
}

void Game::InterpretRoundResult(const rps::ROUND_RESULT& roundResult) {
    switch (roundResult) {
        case ROUND_RESULT::DRAW:
            std::cout << "user gets draw game round" << std::endl;
            break;
        case ROUND_RESULT::LOSE:
            std::cout << "user get lose game round" << std::endl;
            break;
        case ROUND_RESULT::WIN:
            std::cout << "user gets win game round" << std::endl;
            break;
        default:
            break;
    }
}

void Game::run() {
    while (true) {
        auto hChoice = hPlayer_->getRPSChoice();
        auto mChoice = mPlayer_->getRPSChoice();

        auto roundResult = getRoundResult(static_cast<int>(hChoice),
                                          static_cast<int>(mChoice));
        InterpretRoundResult(roundResult);
    }
}

}  // namespace rps