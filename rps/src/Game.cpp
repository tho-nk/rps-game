#include "Game.hpp"

#include <iostream>
#include <memory>

#include "HumainPlayer.hpp"
#include "MachinePlayer.hpp"
#include "HumainStrategy.hpp"
#include "Utilities.hpp"

namespace rps {

Game::Game()
    : mPlayer_(std::make_shared<MachinePlayer>()),
      hPlayer_(std::make_shared<HumainPlayer>()),
      gameDificulty_(std::make_shared<GameDificulty>()) {}

Game::~Game() {}

void Game::configure() {}

void Game::initialize() {
    mPlayer_->setStrategy(gameDificulty_->getGameStrategy());
    hPlayer_->setStrategy(std::make_shared<HumainStrategy>());
}

void Game::changeGameDificulty() {
    std::cout << "please set your level : 0 <-> EASY, 1 <-> MEDIUM, 2 <-> HARD"
              << std::endl;
    gameDificulty_->setLevel(getUserInputIngeter<GAME_LEVEL>(0, 2));
    mPlayer_->setStrategy(gameDificulty_->getGameStrategy());
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
        int i = 0;
        while (i < 3) {
            auto hChoice = hPlayer_->getRPSChoice();
            auto mChoice = mPlayer_->getRPSChoice();

            auto roundResult = getRoundResult(static_cast<int>(hChoice),
                                              static_cast<int>(mChoice));
            InterpretRoundResult(roundResult);
            i++;
        }
        std::cout << "select a new level" << std::endl;
        changeGameDificulty();
    }
}

}  // namespace rps