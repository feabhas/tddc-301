// ring_buffer.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ring_buffer.h"
#include <limits.h>


#define CAPACITY    16

static unsigned count = 0;
static unsigned next_in;
static unsigned next_out;
static int buffer[CAPACITY];



bool buffer_init(void)
{
    count = 0;
    next_in = 0;
    next_out = 0;
    return true;
}

unsigned buffer_count(void)
{
    return count;
}

bool buffer_is_empty(void)
{
    return count == 0;
}

bool buffer_is_full(void)
{
    return count == CAPACITY;;
}

bool buffer_add(int value)
{
    bool rvalue = false;
    if(count < CAPACITY){
        buffer[next_in] = value;
        if(++next_in == CAPACITY) next_in = 0;;
        ++count;
        rvalue = true;
    }
    return rvalue;
}

bool buffer_get(int* value)
{
    bool rvalue = false;
    if(count != 0) {
        --count;
        *value = buffer[next_out];
        if(++next_out ==  CAPACITY) next_out = 0;
        rvalue = true;
    }
    return rvalue;
}

unsigned buffer_capacity(void)
{
    return CAPACITY;
}
