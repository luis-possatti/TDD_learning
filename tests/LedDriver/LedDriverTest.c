#include "unity_fixture.h"
#include <stdint.h>
#include "LedDriver.h"
#include "RuntimeErrorStub.h"

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

TEST(LedDriver, TurnOnAllLEDs)
{
    
    /* action */
    LedDriver_TurnAllOn();

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);

}

TEST(LedDriver, TurnOffAllLEDs)
{
    
    /* action */
    LedDriver_TurnOn(1);
    LedDriver_TurnAllOff();

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtualLeds);

}

TEST(LedDriver, LEDMemoryIsNotReadable)
{
    /* force hardware register have wrong value */
    virtualLeds = 0xFFFF;

    /* action */
    LedDriver_TurnOn(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0x0001, virtualLeds);

    virtualLeds = 0xFFFF;

    /* action */
    LedDriver_TurnOn(8);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0x0081, virtualLeds);

    virtualLeds = 0xFFFF;

    /* action */
    LedDriver_TurnOff(1);

    /* results checkup */
    TEST_ASSERT_EQUAL_HEX16(0x0080, virtualLeds);

}

/* 
 * Test case to ensure is possible to query state of a specific led.
*/
TEST(LedDriver, QueryAndCheckLedIsNotOnAfterCreation)
{
    /* check LED 7 initial state */
    TEST_ASSERT_FALSE(LedDriver_IsOn(7));
}


/* 
 * Test case to ensure the specific state is correct
*/
TEST(LedDriver, QueryAndCheckLedIsOnAfterTurnOn)
{
    /* action */
    LedDriver_TurnOn(7);

    /* checkup */
    TEST_ASSERT_TRUE(LedDriver_IsOn(7));
}

TEST(LedDriver, QueryAndCheckLedIsOffAfterCreation)
{
    /* check LED 8 initial state */
    TEST_ASSERT_TRUE(LedDriver_IsOff(8));
}

TEST(LedDriver, QueryAndCheckLedIsNotOffAfterCreation)
{
    LedDriver_TurnOn(8);

    /* check LED 8 initial state */
    TEST_ASSERT_FALSE(LedDriver_IsOff(8));
}

TEST(LedDriver, TestBoundaryCondictions)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);

    TEST_ASSERT_EQUAL(0x8001, virtualLeds);
}

/* Ensure nothing happens when trying to turn On an out-of-bound LED */
TEST(LedDriver, TestOutOfBoundsInTurnOn)
{
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(165);

    TEST_ASSERT_EQUAL(0, virtualLeds);
}

/* Ensure nothing happens when trying to turn On an out-of-bound LED */
TEST(LedDriver, TestOutOfBoundsInTurnOff)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(165);

    TEST_ASSERT_EQUAL(0xffff, virtualLeds);
}

/* Any out of bound LED is off */
TEST(LedDriver, AnyLEDOutOfBoundsIsOff)
{
    LedDriver_TurnAllOn();


    TEST_ASSERT_FALSE(LedDriver_IsOn(0));
    TEST_ASSERT_TRUE(LedDriver_IsOff(0));

    TEST_ASSERT_FALSE(LedDriver_IsOn(-1));
    TEST_ASSERT_TRUE(LedDriver_IsOff(-1));

    TEST_ASSERT_FALSE(LedDriver_IsOn(17));
    TEST_ASSERT_TRUE(LedDriver_IsOff(17));

    TEST_ASSERT_FALSE(LedDriver_IsOn(19));
    TEST_ASSERT_TRUE(LedDriver_IsOff(19));

    TEST_ASSERT_FALSE(LedDriver_IsOn(165));
    TEST_ASSERT_TRUE(LedDriver_IsOff(165));
}

IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
   /* */
}


/* Ensure a log is performed when trying to turn ON or OFF any led out of bounds */
TEST(LedDriver, OutOfBoundLedsProduceRunTimeErrror)
{
    LedDriver_TurnOn(-1);

    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}
