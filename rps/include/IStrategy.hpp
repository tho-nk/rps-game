#pragma once

#include <iostream>

namespace rps {

enum class RPS_CHOICE { ROCK = 0, PAPER, SCISSORS };

inline std::ostream& operator<<(std::ostream& os, RPS_CHOICE& choice) {
    switch (choice) {
        case RPS_CHOICE::ROCK:
            os << "ROCK";
            break;
        case RPS_CHOICE::PAPER:
            os << "PAPER";
            break;
        case RPS_CHOICE::SCISSORS:
            os << "SCISSORS";
            break;
        default:
            os << "UNDEFINED";
            break;
    }
    return os;
}

class IStrategy {
   public:
    IStrategy() {}
    virtual ~IStrategy() {}

    virtual RPS_CHOICE createRPSChoice() = 0;

   private:
};
}  // namespace rps