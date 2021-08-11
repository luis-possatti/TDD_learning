#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>


typedef struct
{
    int a;
} CircularBuffer_t;


CircularBuffer_t *CircularBuffer_Create(uint8_t size);

bool CircularBuffer_IsEmpty(CircularBuffer_t *buffer);