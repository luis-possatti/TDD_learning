#include "unity_fixture.h"
#include "CircularBuffer.h"


uint16_t circular_buffer_size;
CircularBuffer_t buffer_p;


TEST_GROUP(CircularBufferFull);

TEST_SETUP(CircularBufferFull)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);

}

TEST_TEAR_DOWN(CircularBufferFull)
{
    CircularBuffer_Destroy(buffer_p);
}


TEST(CircularBufferFull, BufferNotFullAfterCreation)
{
    TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer_p));
}

/*
 * Create, write N with N > $Size: full only after writing $Size data.
 * Ensure buffer is only full after writting same number of data
 * than its size. Every subsequent write makes it full
 * 
 */
TEST(CircularBufferFull, BufferFullOnlyAfterWritingToAllItCapability)
{
    uint8_t number_of_data = circular_buffer_size + 5;

    /* Write $Size - 1 data*/
    int i;
    for(i = 0; i < circular_buffer_size - 1; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
        TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer_p));
    }

    /* Write remaining data*/
    for(uint32_t i = circular_buffer_size - 1; i < number_of_data; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
        TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer_p));
    }
}

/*
 * This test cases ensures:
 *  - Buffer becomes not full when a read is perform in a full buffer
 *  - If a write is made, it becomes full again
 */
TEST(CircularBufferFull, ReadsMakeItNotFullAndWriteMakeItFullAgain)
{
    uint8_t number_of_data = circular_buffer_size + 5;

    /* Overflows the buffer */
    int i;
    for(i = 0; i < number_of_data; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
    }

    /* Make a read and ensure it is not full anymore */
    uint32_t data;
    CircularBuffer_ReadValue(buffer_p, &data);
    TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer_p));

    /* Make a write and ensure it is full again */
    CircularBuffer_WriteValue(buffer_p, 0);
    TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer_p));


}

