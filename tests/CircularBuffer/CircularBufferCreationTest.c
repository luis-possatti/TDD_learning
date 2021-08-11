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


