
#include "RockStrategy.hpp"

#include <iostream>
#include <random>

namespace rps {

RockStrategy::RockStrategy() {
    std::cout << "create RockStrategy" << std::endl;
}
RockStrategy::~RockStrategy() {}

RPS_CHOICE RockStrategy::createRPSChoice() { return RPS_CHOICE::ROCK; }
}  // namespace rps