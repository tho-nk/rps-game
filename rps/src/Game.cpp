#include "Game.hpp"

#include <iostream>
#include <memory>

#include "HumainPlayer.hpp"
#include "HumainStrategy.hpp"
#include "MachinePlayer.hpp"
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
    std::cout
        << "0 <-> EASY, 1 <-> MEDIUM, 2 <-> HARD, please select your level : "
        << std::endl;
    const auto level = getUserInputIngeter<GAME_LEVEL>(0, 2);
    gameDificulty_->setLevel(level);
    mPlayer_->setStrategy(gameDificulty_->getGameStrategy());
}

ROUND_RESULT Game::getRoundResult(int hChoice, int mChoice) {
    std::cout << "your choice := " << hChoice
              << ", machine choice := " << mChoice << std::endl;
    return gameReference_[hChoice][mChoice];
}

void Game::InterpretRoundResult(const rps::ROUND_RESULT& roundResult) {
    switch (roundResult) {
        case ROUND_RESULT::DRAW:
            std::cout << "you get a draw round" << std::endl;
            break;
        case ROUND_RESULT::LOSE:
            std::cout << "you get a lose round" << std::endl;
            break;
        case ROUND_RESULT::WIN:
            std::cout << "you get a win round" << std::endl;
            break;
        default:
            std::cout << "undefined result" << std::endl;
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
        std::cout << "Do you like to retry with a new level" << std::endl;
        changeGameDificulty();
    }
}

}  // namespace rps