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

/*
 * Cover the case where a single led can be turned on
 */
TEST(LedDriver, TurnLedOneOn)
{

    /* action */
    LedDriver_TurnOn(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);

}

/*
 * Cover the case where a single led can be turned on and off
 */
TEST(LedDriver, TurnLedOneOnandOff)
{
    
    /* action */
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);

}

/*
 * Cover the case were different LEDs are turned on
 */
TEST(LedDriver, MultipleLedsTurnedOn)
{
    
    /* action */
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);


    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0x0180, virtualLeds);

}

/*
 * Cover the case were different LEDs are turned on and them off
 */
TEST(LedDriver, MultipleLedsTurnedOff)
{
    
    /* action */
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);
    LedDriver_TurnOff(8);
    LedDriver_TurnOff(9);
    
    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);

}

