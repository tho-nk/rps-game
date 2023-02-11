#pragma once

#include <iostream>

#include "IPlayer.hpp"

namespace rps {
class HumainPlayer : public IPlayer {
   public:
    HumainPlayer();
    virtual ~HumainPlayer();

    virtual RPS_CHOICE getRPSChoice() override;
};
}  // namespace rps