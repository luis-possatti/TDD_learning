#include "unity_fixture.h"
#include <stdint.h>
#include "LedDriver.h"

TEST_GROUP(LedDriver);

uint16_t virtualLeds;    


TEST_SETUP(LedDriver)
{

    LedDriver_Creator(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{
    
}

TEST(LedDriver, LedsOffAfterCreate)
{
    virtualLeds = 0xffff;
    LedDriver_Creator(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, TurnLedOneOn)
{
    /* define the virtual leds buffer and create the driver instance*/

    /* action */
    LedDriver_TurnOn(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);

}

TEST(LedDriver, TurnLedOneOnandOff)
{
    
    /* action */
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);

}