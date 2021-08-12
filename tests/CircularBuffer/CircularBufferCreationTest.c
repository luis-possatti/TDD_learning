#include "unity_fixture.h"
#include "CircularBuffer.h"

CircularBuffer_t buffer_p;

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
    buffer_p = CircularBuffer_Create(1);
    TEST_ASSERT_FALSE(buffer_p == NULL)
}

/*
 * This test case cover a simple buffer creation with size 10, not a corner case
*/
TEST(CircularBufferCreation, CreateBufferSize10)
{
    buffer_p = CircularBuffer_Create(10);
    TEST_ASSERT_FALSE(buffer_p == NULL)
}

/*
 * This test case cover a circular buffer creation with size 0
*/
TEST(CircularBufferCreation, CreateBufferSize0)
{
    buffer_p = CircularBuffer_Create(0);
    TEST_ASSERT_TRUE(buffer_p == NULL)
}


