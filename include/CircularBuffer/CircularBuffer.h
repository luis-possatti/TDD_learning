#include <stdint.h>


typedef struct
{
    int a;
} CircularBuffer_t;


CircularBuffer_t *CircularBuffer_Create(uint8_t size);