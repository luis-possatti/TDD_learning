# Requeriments of circular buffer:
- Can be created with a parametrized number of nodes.
- Shall be able to inform if it is empty
- Shall be able to inform if it is full
- A write operation when the buffer is full overwrites the older node and return -1
- A write operation when the buffer is not full return 0
- The read method shall be FIFO method
- A read when the buffer is empty returns -1 
- A read when the buffer is not empty returns 0


# Test list:
## Buffer creation
  - [x] Create buffer with size 10 and receive a valid pointer
  - [x]  Create buffer with size 1 and receive a valid pointer
  - [x]  Create buffer with size 0 and receive null
## Detect buffer empty
  - [ ]  Create buffer and check is empty
  - [ ]  Create buffer write to it and check not empty
  - [ ]  Create buffer write to it, read and check is empty
  - [ ]  Create a buffer write N times and read N times. Ensure not empty for N-1 reads and empty after last read. N < size
  - [ ]  Create a buffer, write 2*$Size. Read $Size times and check not empty for $Size-1 reads and empty after last read. 
## Detect buffer full
  - [ ]  Create a buffer and check not full
  - [ ]  Create a buffer write $(Size - 1) times and check not full
  - [ ]  Create a buffer write $Size times and check is full
  - [ ]  Create a buffer write $Size times and read one time and check is not full 
  - [ ]  Create a buffer write $Size times and read $Size times and check is not full after all the reads.
## Write in circular method:
  - [ ]  Write value $Size times. Check sucess every write.
  - [ ]  Write value $Size times, read one time and write one time and check sucess every write
  - [ ]  Write value $Size times + 1. Check sucess for all the writes, except the last.
  - [ ]  Write value $2*Size times check sucess for first $Size writes and failure  other writes.
  - [ ]  Write $2*Size times, read one time and write one time again. Check sucess for first $Size writes, failure for the others $Size writes and sucess for the last write.
## Read in FIFO method:
  - [ ]  Write a value and read the same value
  - [ ]  Write a value $Size times and read $size times the same
  - [ ]  Write sort of $Size different values and read the same sequence
  - [ ]  Write one value read two times. Check sucess in the first and failure in the second
  - [ ]  Write $size values, read $size times with sucess read one without sucess
  - [ ]  Write a sequence of $Size + 1 values and read $Size + 1 times. The $Size first reads sequence should be sucess and have the values of the last $Size values written. The last read should not be sucessful.
