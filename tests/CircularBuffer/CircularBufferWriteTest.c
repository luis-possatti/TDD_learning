#include "unity_fixture.h"
#include "CircularBuffer.h"


uint8_t circular_buffer_size;
CircularBuffer_t buffer_p;


TEST_GROUP(CircularBufferWrite);

TEST_SETUP(CircularBufferWrite)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);
}

TEST_TEAR_DOWN(CircularBufferWrite)
{

}


TEST(CircularBufferWrite, WriteOneValueToBufferAfterCreation)
{
    uint32_t value = 55;
    int8_t write_result = CircularBuffer_WriteValue(buffer_p, value);
    TEST_ASSERT_EQUAL(0, write_result);
}