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

/* 
 * Write one data and read one, ensure buffer is empty again
 *
 */
TEST(CircularBufferEmpty, BufferIsEmptyAfterReadingTheOnlyData)
{
    uint32_t data;   
    CircularBuffer_WriteValue(buffer_p, 0);
    CircularBuffer_ReadValue(buffer_p, &data);
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer_p));
}

/* 
 * Create, write N and read N, with N < $Size: Empty only after N reads
 *
 */
TEST(CircularBufferEmpty, BufferIsEmptyAfterReadingAllTheDataInBuffer)
{
    uint8_t n = circular_buffer_size - 2;
    uint32_t data;
    int i;
    for(i = 0; i < n; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
        TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(buffer_p));
    }
    for(i = 0; i < n; i++)
    {
        CircularBuffer_ReadValue(buffer_p, &data);
        if(i < n - 1)
        {
            TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(buffer_p));
        }
        else
        {
            TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer_p));
        }
    }
}



/* 
 * Create, write N and read N, with N > $Size: Empty after $size reads
 *
 * This case ensure that the emptyness logic is not break when a overflow occurs.
 * The expected result is that the buffer is empty after reading the number of data equivalent to its size
 */
TEST(CircularBufferEmpty, OverflowOfBufferCapacityNotBreakEmptnessLogic)
{
    uint8_t n = circular_buffer_size + 5;
    uint32_t data;
    int i;
    for(i = 0; i < n; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
        TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(buffer_p));
    }
    for(i = 0; i < circular_buffer_size - 1; i++)
    {
        CircularBuffer_ReadValue(buffer_p, &data);
        TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(buffer_p));
    }
    for(i = circular_buffer_size - 1; i < n; i++)
    {
        CircularBuffer_ReadValue(buffer_p, &data);
        TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer_p));
    }
}

