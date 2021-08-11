#include "CircularBuffer.h"

CircularBuffer_t dummy_buffer;

CircularBuffer_t *CircularBuffer_Create(uint8_t size)
{
    if(size > 0)
    {
        return &dummy_buffer;
    }
    else
    {
        return NULL;
    }
}


bool CircularBuffer_IsEmpty(CircularBuffer_t *buffer)
{
    return true;
}


bool CircularBuffer_IsFull(CircularBuffer_t *buffer)
{
    return false;
}