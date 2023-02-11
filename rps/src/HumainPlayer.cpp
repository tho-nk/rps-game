
#include "HumainPlayer.hpp"

namespace rps {
HumainPlayer::HumainPlayer() {
    std::cout << "create HumainPlayer" << std::endl;
}

HumainPlayer::~HumainPlayer() {}

RPS_CHOICE HumainPlayer::getRPSChoice() {
    const auto choice = strategy_->createRPSChoice();
    std::cout << "Your RPS is : " << choice << std::endl;
    return choice;
}

}  // namespace rps