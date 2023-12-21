// ds18b20.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

/** @file ds18b20.h
    \brief API for the DS18B20 Temperature Sensor.
*/
#ifndef _DS18B20_H
#define _DS18B20_H

#include <stdbool.h>
#include <stdint.h>

/**
 *  Defines the DS18B20 Temperature Sensor Resolution
 */
typedef enum {
    R9  = ~1U, /**<  9-bit Resolution */
    R10 = ~3U, /**< 10-bit Resolution */
    R11 = ~7U, /**< 11-bit Resolution */
    R12 = ~0U  /**< 12-bit Resolution */
} Resolution;


/*! \fn bool ds18b20_initialise(Resolution resolution)
    \brief Initialised the DS18B20 Temperature Sensor.
    \param resolution ```[IN]``` The required resolution.
    \return ```true``` if initialisation was successful.
*/
bool ds18b20_initialise(Resolution resolution);


/*! \fn float ds18b20_convert(uint16_t digital)
    \brief Converts the signed 12.4 fixed point representation to degC.
    \param digital ```[IN]``` The 16-bit raw temperature reading in signed 12.4
    \return The temperature converted to degrees Centigrade.
*/
float ds18b20_convert(uint16_t digital);

#endif // _DS18B20_H
