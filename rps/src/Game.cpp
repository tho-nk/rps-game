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
      gameDificulty_(std::make_shared<GameDificulty>()),
      numberRound_(3) {}

Game::~Game() {}

void Game::configure() {
    setGameDificulty();
    setNumberRound();
}

void Game::initialize() {
    mPlayer_->setStrategy(gameDificulty_->getGameStrategy());
    hPlayer_->setStrategy(std::make_shared<HumainStrategy>());
}

void Game::setGameDificulty() {
    std::cout << "Please select your level : " << std::endl;
    std::cout << "0 <-> EASY" << std::endl;
    std::cout << "1 <-> MEDIUM" << std::endl;
    std::cout << "2 <-> HARD" << std::endl;

    const auto level = getUserInputIngeterToEnum<GAME_LEVEL>();
    std::cout << "Selected Level : " << level << std::endl;
    gameDificulty_->setLevel(level);
    mPlayer_->setStrategy(gameDificulty_->getGameStrategy());
}

ROUND_RESULT Game::getRoundResult(int hChoice, int mChoice) {
    return gameReference_[hChoice][mChoice];
}

void Game::InterpretRoundResult(const rps::ROUND_RESULT& roundResult) {
    switch (roundResult) {
        case ROUND_RESULT::DRAW:
            std::cout << "You get a draw round" << std::endl;
            break;
        case ROUND_RESULT::LOSE:
            std::cout << "You get a lose round" << std::endl;
            break;
        case ROUND_RESULT::WIN:
            std::cout << "You get a win round" << std::endl;
            break;
        default:
            std::cout << "Undefined result" << std::endl;
            break;
    }
}

bool Game::getRetry() {
    char retry;
    do {
        std::cout << "Would you like to retry?(Y/N)" << std::endl;
        std::cin >> retry;
        retry = tolower(retry);
    } while (retry != 'n' && retry != 'y');
    if (retry == 'n') {
        return false;
    }
    return true;
}

void Game::setNumberRound() {
    std::cout
        << "Please Enter number round you want to play(positive integer): ";
    int userInput;
    while (true) {
        std::cin >> userInput;
        if (std::cin.fail() || userInput <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            break;
        }
    }
    numberRound_ = userInput;
    std::cout << "Number round to play: " << numberRound_ << std::endl;
}

void Game::run() {
    bool gameOn = true;

    while (gameOn) {
        int iRound = 0;
        while (iRound < numberRound_) {
            std::cout << "Round : " << iRound + 1 << std::endl;
            auto hChoice = hPlayer_->getRPSChoice();
            auto mChoice = mPlayer_->getRPSChoice();

            auto roundResult = getRoundResult(static_cast<int>(hChoice),
                                              static_cast<int>(mChoice));
            InterpretRoundResult(roundResult);
            iRound++;
        }
        gameOn = getRetry();
        if (gameOn) {
            configure();
        }
    }
}

}  // namespace rps