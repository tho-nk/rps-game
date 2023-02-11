
#include "MachinePlayer.hpp"

namespace rps {
MachinePlayer::MachinePlayer() {
    std::cout << "Create MachinePlayer" << std::endl;
}

MachinePlayer::~MachinePlayer() {}

RPS_CHOICE MachinePlayer::getRPSChoice() {
    auto choice = strategy_->createRPSChoice();
    std::cout << "MachinePlayer's RPS : " << choice << std::endl;
    return choice;
}
}  // namespace rps