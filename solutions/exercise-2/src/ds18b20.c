// ds18b20.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ds18b20.h"
#include <string.h>


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


ds18b20_ROM_t ds18b20_read_rom(void)
{
    ds18b20_ROM_t data = {
        .rom_code.family_code = 0x28,
        .rom_code.serial_number = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6 } ,
        .rom_code.crc = 0x00,
    }; //!OCLINT
    return data;
}

void ds18b20_do_conversion(void)
{
}

bool ds18b20_read_scratchpad(ds18b20_scratchpad_data_t * const data)
{
    // default values
    data->lsb = 0x50;
    data->msb = 0x05;
    data->crc = 0;
    return true;
}

float ds18b20_convert(uint16_t digital)
{
    digital &= mask;
    int16_t s_digital = digital;
    return s_digital / 16.0f;
}


uint8_t ds18b20_calculate_CRC(const uint8_t* data, uint32_t num_of_bytes)
{
    (void)data;
    (void)num_of_bytes;
    return 0;
}


