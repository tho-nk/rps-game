#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

#include "RandStrategy.hpp"
#include "RockStrategy.hpp"
#include "SemiRandStrategy.hpp"

namespace rps {

enum class GAME_LEVEL { EASY, MEDIUM, HARD };

class GameDificulty {
   public:
    GameDificulty() {
        rockStrategy_ = std::make_shared<RockStrategy>();
        semiRandStrategy_ = std::make_shared<SemiRandStrategy>();
        randStrategy_ = std::make_shared<RandStrategy>();
    }
    ~GameDificulty() {}

    std::shared_ptr<IStrategy> getGameStrategy(GAME_LEVEL level) {
        switch (level) {
            case GAME_LEVEL::EASY:
                return rockStrategy_;
                break;
            case GAME_LEVEL::MEDIUM:
                return semiRandStrategy_;
                break;
            case GAME_LEVEL::HARD:
                return randStrategy_;
                break;
            default:
                return rockStrategy_;
                break;
        }
    }

   private:
    std::shared_ptr<IStrategy> rockStrategy_;
    std::shared_ptr<IStrategy> semiRandStrategy_;
    std::shared_ptr<IStrategy> randStrategy_;
};

}  // namespace rps