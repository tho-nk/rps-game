
#include "SemiRandStrategy.hpp"

#include <iostream>
#include <random>

namespace rps {

SemiRandStrategy::SemiRandStrategy() {
    std::cout << "create SemiRandStrategy" << std::endl;
}
SemiRandStrategy::~SemiRandStrategy() {}

RPS_CHOICE SemiRandStrategy::createRPSChoice() {
    if (isRandom_) {
        isRandom_ = false;
        return static_cast<RPS_CHOICE>(std::rand() % 3);
    } else {
        isRandom_ = true;
        return RPS_CHOICE::PAPER;
    }
}
}  // namespace rps