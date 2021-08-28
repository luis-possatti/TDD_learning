#include "unity_fixture.h"


TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnLedOneOn);
    RUN_TEST_CASE(LedDriver, TurnLedOneOnandOff);
    RUN_TEST_CASE(LedDriver, MultipleLedsTurnedOn);
    RUN_TEST_CASE(LedDriver, MultipleLedsTurnedOff);
    RUN_TEST_CASE(LedDriver, TurnOnAllLEDs);
    RUN_TEST_CASE(LedDriver, TurnOffAllLEDs);
}