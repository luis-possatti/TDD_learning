#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize1);
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize10);
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize0);

    RUN_TEST_CASE(CircularBufferEmpty, CreateEmptyBuffer);
    RUN_TEST_CASE(CircularBufferFull, BufferNotFullAfterCreation);

    RUN_TEST_CASE(CircularBufferWrite, WriteOneValueToBufferAfterCreation);
    RUN_TEST_CASE(CircularBufferRead, ReadBeforeAnyWrite);

}

