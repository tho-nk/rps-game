
#include "HumainPlayer.hpp"

namespace rps {
HumainPlayer::HumainPlayer() {
    std::cout << "create HumainPlayer" << std::endl;
}

HumainPlayer::~HumainPlayer() {}

RPS_CHOICE HumainPlayer::getRPSChoice() {
    auto choice = strategy_->createRPSChoice();
    std::cout << "HumainPlayer Choice : " << choice << std::endl;
    return choice;
}

}  // namespace rps