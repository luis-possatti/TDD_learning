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


int8_t CircularBuffer_WriteValue(CircularBuffer_t *buffer, uint32_t value)
{
    return 0;
}


int8_t CircularBuffer_ReadValue(CircularBuffer_t *buffer, uint32_t *data_p)
{
    return -1;
}