#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>



/*
 * Using ADT design pattern. Make public only the typedef of a pointer to
 * the circular buffer, not the circular buffer data.
*/
typedef struct CircularBuffer_struct * CircularBuffer_t;



CircularBuffer_t CircularBuffer_Create(uint8_t size);

void CircularBuffer_Destroy(CircularBuffer_t buffer_p);

bool CircularBuffer_IsEmpty(CircularBuffer_t buffer);

bool CircularBuffer_IsFull(CircularBuffer_t buffer);

int8_t CircularBuffer_WriteValue(CircularBuffer_t buffer, uint32_t value);

int8_t CircularBuffer_ReadValue(CircularBuffer_t buffer, uint32_t *data_p);