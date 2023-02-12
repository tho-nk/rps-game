#include <iostream>
#include <memory>

#include "Game.hpp"

int main() {
    auto aGame = std::make_shared<rps::Game>();
    aGame->initialize();
    aGame->configure();
    std::cout << "Game starts" << std::endl;
    aGame->run();
}