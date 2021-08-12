#include "unity_fixture.h"
#include "CircularBuffer.h"


uint8_t circular_buffer_size;
CircularBuffer_t buffer_p;


TEST_GROUP(CircularBufferRead);

TEST_SETUP(CircularBufferRead)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);
}

TEST_TEAR_DOWN(CircularBufferRead)
{

}


TEST(CircularBufferRead, ReadBeforeAnyWrite)
{
    uint32_t read_value;
    int8_t read_result = CircularBuffer_ReadValue(buffer_p, &read_value);
    TEST_ASSERT_EQUAL(-1, read_result);
}