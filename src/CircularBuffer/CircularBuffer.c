#include "CircularBuffer.h"
#include <stdlib.h>

typedef struct CircularBuffer_struct
{
    int a;
} CircularBuffer_struct;



static CircularBuffer_struct dummy_buffer;
static uint8_t buffer_size;
static uint8_t data_on_buffer;
static uint8_t read_index;
static uint8_t write_index;
static uint32_t *values;


/* Helper functions prototypes */
static void update_read_index(void);
static void update_write_index(void);

/*
************************************************** 
* Public functions definitions - INIT
**************************************************
*/


CircularBuffer_t CircularBuffer_Create(uint8_t size)
{
    if(size > 0)
    {
        buffer_size = size;
        data_on_buffer = 0;
        read_index = 0;
        write_index = 0;
        values = malloc(size*sizeof(uint32_t));
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
        values[write_index] = value;
        data_on_buffer++; /* writes to a free node */
        update_write_index();
        return WRITE_SUCCESS; 
    }
    else
    {
        values[write_index] = value;
        update_read_index();
        update_write_index();
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
        update_read_index();
        data_on_buffer--;
        return READ_SUCCESS;
    }
    else
    {
        return READ_FAILURE;
    }
}


/*
************************************************** 
* Public functions definitions - END
**************************************************
*/


/*
************************************************** 
* Helper functions definitions - INIT
**************************************************
*/




static void update_read_index(void)
{
    read_index++;
    if(read_index == buffer_size)
    {
        read_index = 0;
    }
}

static void update_write_index(void)
{
    write_index++;
    if(write_index == buffer_size)
    {
        write_index = 0;
    }
}

/*
************************************************** 
* Helper functions definitions - END
**************************************************
*/

