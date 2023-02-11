#pragma once

#include <iostream>

#include "IStrategy.hpp"

namespace rps {

class HumainStrategy : public IStrategy {
   public:
    HumainStrategy();
    virtual ~HumainStrategy();

    virtual RPS_CHOICE createRPSChoice() override;
};
}  // namespace rps