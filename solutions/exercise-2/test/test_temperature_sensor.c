// test_temperature_sensor.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "unity.h"
#include "temperature_sensor.h"

// include dependent modules for compilation/linking
#include "ds18b20.h"
#include "lcd.h"

#include <stdio.h>
#include <string.h>

void setUp(void)
{
    bool okay = false;

    okay = ds18b20_initialise(R12);
    TEST_ASSERT_TRUE(okay);

    okay = lcd_initialize();
    TEST_ASSERT_TRUE(okay);
}

void tearDown(void)
{
}

void test_temperature_sensor_initialization_code(void)
{
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_OK);
}

void test_temperature_sensor_main_code(void)
{
    temperture_sensor_initialize();
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_OK);
}
