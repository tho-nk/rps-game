#pragma once

#include <iostream>

#include "IStrategy.hpp"

namespace rps {

class SemiRandStrategy : public IStrategy {
   public:
    SemiRandStrategy();
    virtual ~SemiRandStrategy();

    virtual RPS_CHOICE createRPSChoice() override;

   private:
    static inline bool isRandom_ = false;
};
}  // namespace rps