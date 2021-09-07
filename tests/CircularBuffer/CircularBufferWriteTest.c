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

/*
 * This test case ensures a write is sucess only when the buffer is not full.
 *  The write operation is performed in the following condictions:
 *  - Buffer empty after creation
 *  - Buffer full and overflowed
 *  - Buffer not full after a read
 *  - Buffer full again after two writes
 */
TEST(CircularBufferWrite, EnsureWriteIsOnlySucessWhenBufferNotFull)
{
    uint32_t value = 55;

    int number_of_writes = circular_buffer_size + 5;

    enum {
        SUCESS = 0,
        FAILURE = -1
    };
    /* write $number_of_writes to force overflow situation */
    for(int i = 0; i < number_of_writes; i++)
    {
        if(CircularBuffer_IsFull(buffer_p))
        {
            TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_WriteValue(buffer_p, value));
        }
        else
        {
            TEST_ASSERT_EQUAL_INT8(SUCESS, CircularBuffer_WriteValue(buffer_p, value));
        }
    }

    /* read one data and ensure the next two writes are sucess and failures */
    uint32_t data;
    CircularBuffer_ReadValue(buffer_p, &data);
    TEST_ASSERT_EQUAL_INT8(SUCESS, CircularBuffer_WriteValue(buffer_p, value));
    TEST_ASSERT_EQUAL_INT8(FAILURE, CircularBuffer_WriteValue(buffer_p, value));
}