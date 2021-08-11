#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBufferCreation)
{
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize1);
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize10);
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize0);

    RUN_TEST_CASE(CircularBufferEmpty, CreateEmptyBuffer);
}

