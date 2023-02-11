#include "RandStrategy.hpp"

#include <iostream>
#include <random>

namespace rps {

RandStrategy::RandStrategy() {
    std::cout << "Create RandStrategy" << std::endl;
}
RandStrategy::~RandStrategy() {}

RPS_CHOICE RandStrategy::createRPSChoice() {
    return static_cast<RPS_CHOICE>(std::rand() % 3);
}
}  // namespace rps