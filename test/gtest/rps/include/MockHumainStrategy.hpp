#pragma once
#include "HumainStrategy.hpp"
#include "gmock/gmock.h"  // Brings in gMock.

namespace rps {
class MockHumainStrategy : public HumainStrategy {
   public:
    MOCK_METHOD(RPS_CHOICE, createRPSChoice, (), (override));
};
}  // namespace rps