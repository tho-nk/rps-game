#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

#include "RandStrategy.hpp"
#include "RockStrategy.hpp"
#include "SemiRandStrategy.hpp"

namespace rps {

enum class GAME_LEVEL { BEGIN = 0, EASY = BEGIN, MEDIUM, HARD, COUNT };

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
    static GameDificulty& getInstance() {
        static GameDificulty instance;
        return instance;
    }

    void initialize() {
        rockStrategy_ = std::make_shared<RockStrategy>();
        semiRandStrategy_ = std::make_shared<SemiRandStrategy>();
        randStrategy_ = std::make_shared<RandStrategy>();
        level_ = GAME_LEVEL::EASY;
    }

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
    GameDificulty() {
        std::cout << "create Game Dificulty" << std::endl;
        std::cout << "pre-create all strategies for machine player"
                  << std::endl;
    }

    ~GameDificulty() {}

    std::shared_ptr<IStrategy> rockStrategy_;
    std::shared_ptr<IStrategy> semiRandStrategy_;
    std::shared_ptr<IStrategy> randStrategy_;
    GAME_LEVEL level_;
};

}  // namespace rps