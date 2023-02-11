#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

#include "RandStrategy.hpp"
#include "RockStrategy.hpp"
#include "SemiRandStrategy.hpp"

namespace rps {

enum class GAME_LEVEL { EASY = 0, MEDIUM = 1, HARD = 2 };

inline std::ostream& operator<<(std::ostream& os, const GAME_LEVEL& level) {
    switch (level) {
        case GAME_LEVEL::EASY:
            os << "EASY";
            break;
        case GAME_LEVEL::MEDIUM:
            os << "MEDIUM";
            break;
        case GAME_LEVEL::HARD:
            os << "HARD";
            break;
        default:
            os << "UNDEFINED";
            break;
    }
    return os;
}

class GameDificulty {
   public:
    GameDificulty()
        : rockStrategy_(std::make_shared<RockStrategy>()),
          semiRandStrategy_(std::make_shared<SemiRandStrategy>()),
          randStrategy_(std::make_shared<RandStrategy>()),
          level_(GAME_LEVEL::EASY) {}

    ~GameDificulty() {}

    std::shared_ptr<IStrategy> getGameStrategy() {
        switch (level_) {
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

    void setLevel(const GAME_LEVEL& level) { level_ = level; }

   private:
    std::shared_ptr<IStrategy> rockStrategy_;
    std::shared_ptr<IStrategy> semiRandStrategy_;
    std::shared_ptr<IStrategy> randStrategy_;
    GAME_LEVEL level_;
};

}  // namespace rps