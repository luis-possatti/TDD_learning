#include "unity_fixture.h"
#include <stdint.h>
#include "LedDriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
    
}

TEST_TEAR_DOWN(LedDriver)
{
    
}

TEST(LedDriver, LedsOffAfterCreate)
{
    uint16_t virtualLeds = 0xffff;
    LedDriver_Creator(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

