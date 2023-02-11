#pragma once

#include <iostream>

#include "IPlayer.hpp"

namespace rps {
class MachinePlayer : public IPlayer {
   public:
    MachinePlayer();
    virtual ~MachinePlayer();
    virtual RPS_CHOICE getRPSChoice() override;
};
}  // namespace rps