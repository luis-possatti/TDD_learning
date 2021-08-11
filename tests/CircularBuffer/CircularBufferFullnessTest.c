#include "unity_fixture.h"
#include "CircularBuffer.h"


uint8_t circular_buffer_size;
CircularBuffer_t *buffer_p;


TEST_GROUP(CircularBufferFull);

TEST_SETUP(CircularBufferFull)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);

}

TEST_TEAR_DOWN(CircularBufferFull)
{

}


TEST(CircularBufferFull, BufferNotFullAfterCreation)
{
    TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer_p));
}