#include "CircularBuffer.h"

CircularBuffer_t dummy_buffer;

CircularBuffer_t *CircularBuffer_Create(uint8_t size)
{
    return &dummy_buffer;
}