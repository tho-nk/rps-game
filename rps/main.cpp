#include <iostream>
#include <memory>

#include "Game.hpp"

int main() {
    auto aGame = std::make_shared<rps::Game>();
    aGame->configure();
    aGame->initialize();
    aGame->run();
    std::cout << "hello tho" << std::endl;
}