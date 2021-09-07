      - Check that every write when buffer is returns a overwritten
# Requeriments of circular buffer:
- Can be created with a parametrized number of nodes.
- Shall be able to inform if it is empty
- Shall be able to inform if it is full
- A write operation when the buffer is not full writes to a free node and return 0
- A write operation when the buffer is full overwrites the older node and return -1
- The read method shall be FIFO method
- A read when the buffer is empty returns -1 
- A read when the buffer is not empty returns 0


# Test list
## Notes:
The test list below is a remodeled version of the first one, trying to apply the following principle:
  - Each case tests **only one different** behaviour.
  - Different funcionalities are checked in different test cases:
    - Ex: When buffer is full, the write operation should return a flag indicating that the oldest value was overwritten:
      - The test cases that checks the write operations only ensures that the correct flag is returned.
      - The overwritten of the oldest values if covered by a test cases that compares the read values to the written ones.
  - The credit of early test cases are used in the latter ones:
    - If I already tested the fullness state of the buffer in a lot of sequences of R/W ops and ensure it is right, to test the right overwrite feedback in a write operation I can:
      - Create a sequence of R/W ops that **I already tested** and **already trust** that the buffer will transit between full and not full,
      - Check that every write when buffer is full returns a overwritten flag
      - Check that every write when buffer is NOT full NOT returns a overwritten flag

    - **Moreover:** to test that the oldest value is the one lost when a overwritten occurs I can:
      - Create a R/W operations sequence that **I already tested**, and then, that **I can trust** that will cause overwrittens and check that the oldest values are missing in the buffer.

## Buffer creation:
 - [x] Create with size 1 and valid pointer
 - [x] Create with size 10 and valid pointer
 - [x] Create with size 0 and NULL



## Emptyness
 -  [x] Empty after creation.
 -  [x] Create and write one: not empty
 -  [x] Create, write one and read one: empty
 -  [x] Create, write N and read N, with N < $Size: Empty only after N reads
 -  [x] Create, write N and read N, with N > $Size: Empty after $size reads

## Fullness
 -  [x] after creation: not full.
 -  [x] Create, write N , with N > $Size: Full after $Size writes until last one
 -  [] Create, write N and read one, with N = $Size: full only after last write, not full after read
 -  [] Create, write N and read one and write one, with N = $Size: not full after read and full again
 -  [] Create, write N and read one and write one, with N > $Size: not full after read and full again


## Write operation inform correctly the overwritten occurrence:
 - [x] Create and write one time, ensure sucess.
 - [] Create, write until overflow, read one, write two again and ensure write is only sucess when not full

## Read sucess:
 - [x] Create and read one time: ensure not sucess.
 - [] Create, read N times, write until overflows and read until empty times and ensure read is sucess only when not empty


## Write and read like FIFO:
 -  [] Write one value and read same value
 -  [] Write N times same value and read N times same value, N < $Size
 -  [] Write N times a set of distinct values and read N times the same sequence in inverted order, with N < $size
 -  [] Write N times a set of distinct values and read $Size times. The read sequence shall be the inverted sequence of the last $Size writes.

## Ensure different modules are independent for each other:
 - Define some tests to make the module work with different buffers and ensure indepency
## Tests with undefined behaviour:
 -  [] What should be the value in the pointer when read request with buffer empty?