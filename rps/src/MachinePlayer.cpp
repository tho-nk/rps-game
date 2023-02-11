
#include "MachinePlayer.hpp"

namespace rps {
MachinePlayer::MachinePlayer() {
    std::cout << "create MachinePlayer" << std::endl;
}

MachinePlayer::~MachinePlayer() {}

RPS_CHOICE MachinePlayer::getRPSChoice() {
    auto choice = strategy_->createRPSChoice();
    std::cout << "MachinePlayer Choice : " << choice << std::endl;
    return choice;
}
}  // namespace rps