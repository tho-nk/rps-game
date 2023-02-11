
#include "HumainStrategy.hpp"

#include <iostream>

#include "Utilities.hpp"

namespace rps {

HumainStrategy::HumainStrategy() {
    std::cout << "create HumainStrategy" << std::endl;
}
HumainStrategy::~HumainStrategy() {}

RPS_CHOICE HumainStrategy::createRPSChoice() {
    std::cout
        << "please set your choice : 0 <-> ROCK, 1 <-> PAPER, 2 <-> SCISSORS"
        << std::endl;
    return getUserInputIngeter<RPS_CHOICE>(0, 2);
}
}  // namespace rps