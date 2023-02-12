#include "Game.hpp"

#include <iostream>
#include <memory>

#include "HumainStrategy.hpp"
#include "Utilities.hpp"

namespace rps {

Game::Game(std::shared_ptr<MachinePlayer> mPlayer,
           std::shared_ptr<HumainPlayer> hPlayer, int numberRound)
    : mPlayer_(mPlayer), hPlayer_(hPlayer), numberRound_(numberRound) {}

Game::~Game() {}

void Game::configure() {
    setGameDificulty_();
    setNumberRound_();
}

void Game::initialize() {
    GameDificulty::getInstance().initialize();
    initializeHumainPlayer_();
}

void Game::initializeHumainPlayer_() {
    hPlayer_->setStrategy(std::make_shared<HumainStrategy>());
}

void Game::setGameDificulty_() {
    std::cout << "Please select your level : " << std::endl;
    std::cout << "0 <-> EASY" << std::endl;
    std::cout << "1 <-> MEDIUM" << std::endl;
    std::cout << "2 <-> HARD" << std::endl;

    const auto level = getUserInputIngeterToEnum<GAME_LEVEL>();
    std::cout << "Selected Level : " << level << std::endl;
    GameDificulty::getInstance().setLevel(level);
    mPlayer_->setStrategy(GameDificulty::getInstance().getGameStrategy());
}

ROUND_RESULT Game::getRoundResult(int hChoice, int mChoice) {
    return gameReference_[hChoice][mChoice];
}

void Game::interpretRoundResult_(const rps::ROUND_RESULT& roundResult,
                                 Result& result) {
    switch (roundResult) {
        case ROUND_RESULT::DRAW:
            std::cout << "You get a draw round" << std::endl;
            result.draw++;
            break;
        case ROUND_RESULT::LOSE:
            std::cout << "You get a lose round" << std::endl;
            result.lose++;
            break;
        case ROUND_RESULT::WIN:
            std::cout << "You get a win round" << std::endl;
            result.win++;
            break;
        default:
            std::cout << "Undefined result" << std::endl;
            break;
    }
}

bool Game::getRetry_() {
    char retry;
    do {
        std::cout << "Would you like to retry new game?(Y/N)" << std::endl;
        std::cin >> retry;
        retry = tolower(retry);
    } while (retry != 'n' && retry != 'y');
    if (retry == 'n') {
        return false;
    }
    return true;
}

void Game::setNumberRound_() {
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

void Game::interpretGameResult_(const Result& result) {
    std::cout << "You get " << result.win << " wins(s), " << result.draw
              << " draw(s), and " << result.lose << " loses" << std::endl;
}

void Game::run() {
    bool gameOn = true;

    while (gameOn) {
        int iRound = 0;
        Result result;
        while (iRound < numberRound_) {
            std::cout << "Round : " << iRound + 1 << std::endl;
            auto hChoice = hPlayer_->getRPSChoice();
            auto mChoice = mPlayer_->getRPSChoice();

            auto roundResult = getRoundResult(static_cast<int>(hChoice),
                                              static_cast<int>(mChoice));
            interpretRoundResult_(roundResult, result);
            iRound++;
        }
        interpretGameResult_(result);
        gameOn = getRetry_();
        if (gameOn) {
            configure();
        }
    }
}

}  // namespace rps