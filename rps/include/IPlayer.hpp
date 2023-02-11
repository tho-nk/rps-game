#pragma once

#include <iostream>
#include <memory>

#include "IStrategy.hpp"

namespace rps {
class IPlayer {
   public:
    IPlayer() {}
    virtual ~IPlayer() {}

    void setStrategy(const std::shared_ptr<IStrategy> strategy) {
        strategy_ = strategy;
    }

    virtual RPS_CHOICE getRPSChoice() = 0;

   protected:
    std::shared_ptr<IStrategy> strategy_;
};
}  // namespace rps