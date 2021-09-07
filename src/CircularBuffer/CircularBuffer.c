#include "CircularBuffer.h"


typedef struct CircularBuffer_struct
{
    int a;
} CircularBuffer_struct;


CircularBuffer_struct dummy_buffer;
uint8_t buffer_size;
uint8_t data_on_buffer;
static uint8_t read_index;

static uint32_t values[10];


CircularBuffer_t CircularBuffer_Create(uint8_t size)
{
    if(size > 0)
    {
        buffer_size = size;
        data_on_buffer = 0;
        read_index = 0;
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
    if(data_on_buffer >= buffer_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Definition of the Write operation return codes*/
enum {
    WRITE_FAILURE = -1,
    WRITE_SUCCESS = 0,
};

int8_t CircularBuffer_WriteValue(CircularBuffer_t buffer, uint32_t value)
{
    if(!CircularBuffer_IsFull(buffer))
    {
        values[data_on_buffer] = value;
        data_on_buffer++; /* writes to a free node */
        return WRITE_SUCCESS; 
    }
    else
    {
        return WRITE_FAILURE; /* overwrites*/
    }


}

/* Definition of the Read operation return codes*/
enum {
    READ_FAILURE = -1,
    READ_SUCCESS = 0,
};

int8_t CircularBuffer_ReadValue(CircularBuffer_t buffer, uint32_t *data_p)
{
    if(!CircularBuffer_IsEmpty(buffer))
    {
        *data_p = values[read_index];
        read_index++;
        data_on_buffer--;
        return READ_SUCCESS;
    }
    else
    {
        return READ_FAILURE;
    }
}