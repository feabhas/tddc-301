// ring_buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>

// 1. They need to initialize the circular buffer
bool buffer_init(void);

// 2. They need to know the current number of elements in the buffer
unsigned buffer_count(void);

// 3. They need to know whether the buffer is full or empyty
bool buffer_is_empty(void);
bool buffer_is_full(void);

// 4. They need to be able to add data to the buffer
bool buffer_add(int value);

// 4. They need to be able to get the next value from the buffer
bool buffer_get(int* value);

// 5. They need to know the max capacity of the buffer
unsigned buffer_capacity(void);

// 2. They need to reset the circular buffer
void reset(void);

//

#endif // RING_BUFFER_H
