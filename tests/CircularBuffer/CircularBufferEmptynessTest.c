#include "unity_fixture.h"
#include "CircularBuffer.h"



uint8_t circular_buffer_size;
CircularBuffer_t buffer_p;


TEST_GROUP(CircularBufferEmpty);

TEST_SETUP(CircularBufferEmpty)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);

}

TEST_TEAR_DOWN(CircularBufferEmpty)
{

}


TEST(CircularBufferEmpty, BufferIsEmptyAfterCreation)
{
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer_p));
}


/* 
 * Write one data and ensure buffer is not empty
 *
 */
TEST(CircularBufferEmpty, BufferIsNotEmptyAfterWritingData)
{
    CircularBuffer_WriteValue(buffer_p, 0);
    TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(buffer_p));
}

