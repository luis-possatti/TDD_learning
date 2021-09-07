#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize1);
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize10);
    RUN_TEST_CASE(CircularBufferCreation, CreateBufferSize0);

    RUN_TEST_CASE(CircularBufferEmpty, BufferIsEmptyAfterCreation);
    RUN_TEST_CASE(CircularBufferEmpty, BufferIsNotEmptyAfterWritingData);
    RUN_TEST_CASE(CircularBufferEmpty, BufferIsEmptyAfterReadingTheOnlyData);
    RUN_TEST_CASE(CircularBufferEmpty, BufferIsEmptyAfterReadingAllTheDataInBuffer);
    RUN_TEST_CASE(CircularBufferEmpty, OverflowOfBufferCapacityNotBreakEmptnessLogic);



    RUN_TEST_CASE(CircularBufferFull, BufferNotFullAfterCreation);
    RUN_TEST_CASE(CircularBufferFull, BufferFullOnlyAfterWritingToAllItCapability)

    RUN_TEST_CASE(CircularBufferWrite, WriteOneValueToBufferAfterCreation);
    RUN_TEST_CASE(CircularBufferRead, ReadBeforeAnyWrite);
}

