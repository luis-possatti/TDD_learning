#include "unity_fixture.h"
#include "CircularBuffer.h"



uint8_t circular_buffer_size;
CircularBuffer_t *buffer_p;


TEST_GROUP(CircularBufferEmpty);

TEST_SETUP(CircularBufferEmpty)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);

}

TEST_TEAR_DOWN(CircularBufferEmpty)
{

}


TEST(CircularBufferEmpty, CreateEmptyBuffer)
{
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer_p));
}
