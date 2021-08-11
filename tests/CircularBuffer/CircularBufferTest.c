#include "unity_fixture.h"
#include "CircularBuffer.h"
TEST_GROUP(CircularBufferCreation);

TEST_SETUP(CircularBufferCreation)
{

}

TEST_TEAR_DOWN(CircularBufferCreation)
{

}

/*
 * This test case cover a simple buffer creation with size 1
*/
TEST(CircularBufferCreation, CreateBufferSize1)
{
    CircularBuffer_t *pointer = CircularBuffer_Create(1);
    TEST_ASSERT_FALSE(pointer == NULL)
}

/*
 * This test case cover a simple buffer creation with size 10, not a corner case
*/
TEST(CircularBufferCreation, CreateBufferSize10)
{
    CircularBuffer_t *pointer = CircularBuffer_Create(10);
    TEST_ASSERT_FALSE(pointer == NULL)
}

/*
 * This test case cover a circular buffer creation with size 0
*/
TEST(CircularBufferCreation, CreateBufferSize0)
{
    CircularBuffer_t *pointer = CircularBuffer_Create(0);
    TEST_ASSERT_TRUE(pointer == NULL)
}



TEST_GROUP(CircularBufferEmpty);

uint8_t circular_buffer_size;
CircularBuffer_t *buffer_p;

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