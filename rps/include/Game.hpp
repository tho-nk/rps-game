#pragma once

#include <array>
#include <iostream>
#include <memory>

#include "GameDificulty.hpp"
#include "HumainPlayer.hpp"
#include "IPlayer.hpp"
#include "MachinePlayer.hpp"

namespace rps {

enum class ROUND_RESULT { BEGIN = 0, DRAW = BEGIN, LOSE, WIN, COUNT };

struct Result {
    int win = 0;
    int draw = 0;
    int lose = 0;
};

class Game {
   public:
    Game(std::shared_ptr<MachinePlayer> mPlayer =
             std::make_shared<MachinePlayer>(),
         std::shared_ptr<HumainPlayer> hPlayer =
             std::make_shared<HumainPlayer>(),
         int numberRound = 3);
    ~Game();

    void configure();
    void initialize();
    void run();

    ROUND_RESULT getRoundResult(int hChoice, int mChoice);

   private:
    void interpretRoundResult_(const rps::ROUND_RESULT& roundResult,
                               Result& result);
    bool getRetry_();
    void setGameDificulty_();
    void setNumberRound_();
    void initializeHumainPlayer_();
    void interpretGameResult_(const Result& result);

    std::shared_ptr<IPlayer> mPlayer_;
    std::shared_ptr<IPlayer> hPlayer_;

    int numberRound_;

    inline static const std::array<std::array<ROUND_RESULT, 3>, 3>
        gameReference_ = {
            {{ROUND_RESULT::DRAW, ROUND_RESULT::LOSE, ROUND_RESULT::WIN},
             {ROUND_RESULT::WIN, ROUND_RESULT::DRAW, ROUND_RESULT::LOSE},
             {ROUND_RESULT::LOSE, ROUND_RESULT::WIN, ROUND_RESULT::DRAW}}};
};
}  // namespace rps