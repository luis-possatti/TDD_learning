#include "unity_fixture.h"
#include "CircularBuffer.h"


uint8_t circular_buffer_size;
CircularBuffer_t buffer_p;

enum {
    SUCCESS = 0,
    FAILURE = -1
};


TEST_GROUP(CircularBufferRW);

TEST_SETUP(CircularBufferRW)
{
    circular_buffer_size = 10;
    buffer_p = CircularBuffer_Create(circular_buffer_size);
}

TEST_TEAR_DOWN(CircularBufferRW)
{

}

TEST(CircularBufferRW, WriteSuccessfullyToBufferAfterCreation)
{
    uint32_t value = 55;
    TEST_ASSERT_EQUAL_INT8(SUCCESS, CircularBuffer_WriteValue(buffer_p, value));
}

/*
 * This test case ensures a write is sucess only when the buffer is not full.
 *  The write operation is performed in the following condictions:
 *  - Buffer empty after creation
 *  - Buffer full and overflowed
 *  - Buffer not full after a read
 *  - Buffer full again after two writes
 */
TEST(CircularBufferRW, EnsureWriteIsOnlySucessWhenBufferNotFull)
{
    uint32_t value = 55;

    int number_of_writes = circular_buffer_size + 5;

    /* write $number_of_writes to force overflow situation */
    for(int i = 0; i < number_of_writes; i++)
    {
        if(CircularBuffer_IsFull(buffer_p))
        {
            TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_WriteValue(buffer_p, value));
        }
        else
        {
            TEST_ASSERT_EQUAL_INT8(SUCCESS, CircularBuffer_WriteValue(buffer_p, value));
        }
    }

    /* read one data and ensure the next two writes are sucess and failures */
    uint32_t data;
    CircularBuffer_ReadValue(buffer_p, &data);
    TEST_ASSERT_EQUAL_INT8(SUCCESS, CircularBuffer_WriteValue(buffer_p, value));
    TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_WriteValue(buffer_p, value));
}

/* Ensure that a failure is returned if buffer is read right after creation */
TEST(CircularBufferRW, ReadBeforeAnyWriteIsAFailure)
{
    uint32_t read_value;
    TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_ReadValue(buffer_p, &read_value));
}

/* 
 * Ensure that the result of read is compatible with the emptyness state of the buffer:
 *  - Buffer empty: result is failure
 *  - Buffer not empty: result is sucess
 * 
 * The circular buffer will transit and it will be read in the following states:
 *  - Empty after creation
 *  - Full after overflow
 *  - Empty again after reading all the data
*/
TEST(CircularBufferRW, ReadIsSucessOnlyIfBufferNotEmpty)
{
    uint32_t read_value;
    
    /* read the empty buffer 5 times */
    for(int i = 0; i < 5; i++)
    {
        TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_ReadValue(buffer_p, &read_value));
    }

    /* write and overflows the buffer */
    for(int i = 0; i < circular_buffer_size + 5; i++)
    {
        CircularBuffer_WriteValue(buffer_p, 0);
    }

    /* read until buffer is not empty*/
    while(!CircularBuffer_IsEmpty(buffer_p))
    {
        TEST_ASSERT_EQUAL_INT8(SUCCESS, CircularBuffer_ReadValue(buffer_p, &read_value));
    }
}

/* Case to ensure the data written is the same read */
TEST(CircularBufferRW, WriteAndReadSameValue)
{
    uint32_t data_write = 0;
    uint32_t data_read = 0xff;

    
    CircularBuffer_WriteValue(buffer_p, data_write);
    CircularBuffer_ReadValue(buffer_p, &data_read);

    TEST_ASSERT_EQUAL_UINT32(data_write, data_read);

}