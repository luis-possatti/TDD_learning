#include "unity_fixture.h"
#include "CircularBuffer.h"


uint8_t circular_buffer_size;
CircularBuffer_t buffer_p;


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

/*
 * Create, write N with N = $Size: full only after last write
 * Ensure buffer is only full after writting same number of data
 * than its size.
 * 
 */
TEST(CircularBufferFull, BufferNotFullWhenWritingLessDataThanItsSize)
{
    uint8_t number_of_data = circular_buffer_size;

    /* Write all the data except the last one*/
    int i;
    for(i = 0; i < number_of_data - 1; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
        TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer_p));
    }

    CircularBuffer_WriteValue(buffer_p, 0);
    TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer_p));
}