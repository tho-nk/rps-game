#pragma once

#include <array>
#include <iostream>
#include <memory>

#include "GameDificulty.hpp"
#include "IPlayer.hpp"

namespace rps {

enum class ROUND_RESULT { BEGIN = 0, DRAW = BEGIN, LOSE, WIN, COUNT };

class Game {
   public:
    Game();
    ~Game();

    void configure();
    void initialize();
    void run();

   private:
    ROUND_RESULT getRoundResult(int hChoice, int mChoice);
    void InterpretRoundResult(const rps::ROUND_RESULT& roundResult);
    bool getRetry();
    void setGameDificulty();
    void setNumberRound();

    std::shared_ptr<IPlayer> mPlayer_;
    std::shared_ptr<IPlayer> hPlayer_;

    std::shared_ptr<GameDificulty> gameDificulty_;
    int numberRound_;

    inline static const std::array<std::array<ROUND_RESULT, 3>, 3>
        gameReference_ = {
            {{ROUND_RESULT::DRAW, ROUND_RESULT::LOSE, ROUND_RESULT::WIN},
             {ROUND_RESULT::WIN, ROUND_RESULT::DRAW, ROUND_RESULT::LOSE},
             {ROUND_RESULT::LOSE, ROUND_RESULT::WIN, ROUND_RESULT::DRAW}}};
};
}  // namespace rps