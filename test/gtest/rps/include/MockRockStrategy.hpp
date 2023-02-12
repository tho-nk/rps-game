#pragma once
#include "RockStrategy.hpp"
#include "gmock/gmock.h"  // Brings in gMock.

namespace rps {
class MockRockStrategy : public RockStrategy {
   public:
    MOCK_METHOD(RPS_CHOICE, createRPSChoice, (), (override));
};
}  // namespace rps