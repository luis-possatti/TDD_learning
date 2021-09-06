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
    RUN_TEST_CASE(LedDriver, LEDMemoryIsNotReadable);
    RUN_TEST_CASE(LedDriver, QueryAndCheckLedIsNotOnAfterCreation);
    RUN_TEST_CASE(LedDriver, QueryAndCheckLedIsOnAfterTurnOn);
    RUN_TEST_CASE(LedDriver, QueryAndCheckLedIsOffAfterCreation);
    RUN_TEST_CASE(LedDriver, QueryAndCheckLedIsNotOffAfterCreation);
    RUN_TEST_CASE(LedDriver, TestBoundaryCondictions);
    RUN_TEST_CASE(LedDriver, TestOutOfBoundsInTurnOn);
    RUN_TEST_CASE(LedDriver, TestOutOfBoundsInTurnOff);
    RUN_TEST_CASE(LedDriver, AnyLEDOutOfBoundsIsOff)
    RUN_TEST_CASE(LedDriver, OutOfBoundsToDo);

}