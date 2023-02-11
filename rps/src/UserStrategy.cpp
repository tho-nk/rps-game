
#include "UserStrategy.hpp"

#include <iostream>
#include <limits>

namespace rps {

UserStrategy::UserStrategy() {
    std::cout << "create UserStrategy" << std::endl;
}
UserStrategy::~UserStrategy() {}

RPS_CHOICE UserStrategy::createRPSChoice() {
    std::cout
        << "please set your choice : 0 <-> ROCK, 1 <-> PAPER, 2 <-> SCISSORS"
        << std::endl;
    int userInput;
    while (true) {
        std::cout << "Enter an integer between "
                  << static_cast<int>(RPS_CHOICE::ROCK) << " and "
                  << static_cast<int>(RPS_CHOICE::SCISSORS) << ": ";
        std::cin >> userInput;

        if (std::cin.fail() || userInput < static_cast<int>(RPS_CHOICE::ROCK) ||
            userInput > static_cast<int>(RPS_CHOICE::SCISSORS)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        } else {
            break;
        }
    }

    return static_cast<RPS_CHOICE>(userInput);
}
}  // namespace rps