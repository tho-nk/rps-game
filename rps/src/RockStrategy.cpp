
#include "RockStrategy.hpp"

#include <iostream>
#include <random>

namespace rps {

RockStrategy::RockStrategy() {
    std::cout << "Create RockStrategy" << std::endl;
}
RockStrategy::~RockStrategy() {}

RPS_CHOICE RockStrategy::createRPSChoice() { return RPS_CHOICE::ROCK; }
}  // namespace rps