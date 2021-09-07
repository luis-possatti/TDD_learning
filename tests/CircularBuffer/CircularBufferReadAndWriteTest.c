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

TEST(CircularBufferRW, WriteOneValueToBufferAfterCreation)
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


TEST(CircularBufferRW, ReadBeforeAnyWrite)
{
    uint32_t read_value;
    TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_ReadValue(buffer_p, &read_value));
}

