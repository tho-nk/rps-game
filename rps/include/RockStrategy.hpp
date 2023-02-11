#pragma once

#include <iostream>

#include "IStrategy.hpp"

namespace rps {

class RockStrategy : public IStrategy {
   public:
    RockStrategy();
    virtual ~RockStrategy();

    virtual RPS_CHOICE createRPSChoice() override;
};
}  // namespace rps