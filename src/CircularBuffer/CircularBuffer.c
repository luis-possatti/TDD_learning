#include "CircularBuffer.h"

typedef struct CircularBuffer_struct
{
    int a;
} CircularBuffer_struct;


CircularBuffer_struct dummy_buffer;
uint8_t buffer_size;
uint8_t data_on_buffer;

CircularBuffer_t CircularBuffer_Create(uint8_t size)
{
    if(size > 0)
    {
        buffer_size = size;
        data_on_buffer = 0;
        return &dummy_buffer;
    }
    else
    {
        return NULL;
    }
}


bool CircularBuffer_IsEmpty(CircularBuffer_t buffer)
{
    if(data_on_buffer == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool CircularBuffer_IsFull(CircularBuffer_t buffer)
{
    return false;
}


int8_t CircularBuffer_WriteValue(CircularBuffer_t buffer, uint32_t value)
{
    data_on_buffer++;
    if(data_on_buffer > buffer_size)
    {
        data_on_buffer = buffer_size;
    }
    return 0;
}


int8_t CircularBuffer_ReadValue(CircularBuffer_t buffer, uint32_t *data_p)
{
    if(data_on_buffer > 0)
    {
        data_on_buffer--;
    }
    return -1;
}