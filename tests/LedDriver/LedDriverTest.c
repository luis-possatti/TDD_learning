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

TEST(LedDriver, TurnLedOneOn)
{
    /* define the virtual leds buffer and create the driver instance*/
    uint16_t virtualLeds;
    LedDriver_Creator(&virtualLeds);

    /* action */
    LedDriver_TurnOn(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);

}