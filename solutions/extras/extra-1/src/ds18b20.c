// ds18b20.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ds18b20.h"

static uint16_t mask;

bool ds18b20_initialise(Resolution resolution)
{
    bool okay = true;
    switch(resolution) {
        case R9:
        case R10:
        case R11:
        case R12:
            mask = resolution;
            break;
        default:
            mask = 0;
            okay = false;
            break;
    }
    return okay;
}

float ds18b20_convert(uint16_t digital)
{
    digital &= mask;
    int16_t s_digital = digital;
    return s_digital / 16.0f;
}
