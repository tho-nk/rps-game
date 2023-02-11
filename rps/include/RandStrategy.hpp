#pragma once

#include <iostream>

#include "IStrategy.hpp"

namespace rps {

class RandStrategy : public IStrategy {
   public:
    RandStrategy();
    virtual ~RandStrategy();

    virtual RPS_CHOICE createRPSChoice() override;
};
}  // namespace rps