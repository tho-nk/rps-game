
#include "HumainStrategy.hpp"

#include <iostream>

#include "Utilities.hpp"

namespace rps {

HumainStrategy::HumainStrategy() {
    std::cout << "Create HumainStrategy" << std::endl;
}
HumainStrategy::~HumainStrategy() {}

RPS_CHOICE HumainStrategy::createRPSChoice() {
    std::cout << "Please select your RPS" << std::endl;
    std::cout << "0 <-> ROCK" << std::endl;
    std::cout << "1 <-> PAPER" << std::endl;
    std::cout << "2 <-> SCISSORS" << std::endl;
    return getUserInputIngeterToEnum<RPS_CHOICE>();
}
}  // namespace rps