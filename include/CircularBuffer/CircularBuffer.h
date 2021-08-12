#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


typedef struct
{
    int a;
} CircularBuffer_t;


CircularBuffer_t *CircularBuffer_Create(uint8_t size);

bool CircularBuffer_IsEmpty(CircularBuffer_t *buffer);

bool CircularBuffer_IsFull(CircularBuffer_t *buffer);

int8_t CircularBuffer_WriteValue(CircularBuffer_t *buffer, uint32_t value);

int8_t CircularBuffer_ReadValue(CircularBuffer_t *buffer, uint32_t *data_p);