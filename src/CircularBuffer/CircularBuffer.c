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