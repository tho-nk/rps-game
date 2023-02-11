#pragma once

#include <iostream>

#include "IStrategy.hpp"

namespace rps {

class UserStrategy : public IStrategy {
   public:
    UserStrategy();
    virtual ~UserStrategy();

    virtual RPS_CHOICE createRPSChoice() override;

   private:
};
}  // namespace rps