// test_temperature_sensor.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "unity.h"
#include "temperature_sensor.h"


// include dependent modules for compilation/linking
#include "mock_ds18b20.h"
#include "mock_lcd.h"

#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_temperature_sensor_initialization_code(void)
{
    TEST_IGNORE();
    lcd_initialize_ExpectAndReturn(false);

    // Call UUT
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_OK);
}



void test_temperature_sensor_main_code(void)
{
    TEST_IGNORE();

    // run UUT
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_OK);
}


///// INITIALIZATION FAILURE TESTS /////
void test_temperature_sensor_initialization_lcd_failure(void)
{
    TEST_IGNORE();
    lcd_initialize_ExpectAndReturn(false);  // set to fail

    // Call UUT
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_LCD_FALIURE);
}


void test_temperature_sensor_initialization_ds18b20_failure(void)
{
    TEST_IGNORE();

    // Call UUT
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_DS18B20_FALURE);

}


void test_temperature_sensor_initialization_crc_fail(void)
{
    TEST_IGNORE();

    // Call UUT
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_DS18B20_FALURE);
}

void test_temperature_sensor_initialization_lcd_write_fail_family(void)
{
    TEST_IGNORE();

    // Call UUT
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_LCD_FALIURE);
}

void test_temperature_sensor_initialization_lcd_write_fail_sn(void)
{
    TEST_IGNORE();

    // Call UUT
    temperture_status_t rvalue = temperture_sensor_initialize();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_LCD_FALIURE);
}

///// MAIN FAILURE TESTS /////
void test_temperature_sensor_main_code_read_scratchpad_error(void)
{
    TEST_IGNORE();

    // run UUT
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_DS18B20_FALURE);
}

void test_temperature_sensor_main_code_crc_error(void)
{
    TEST_IGNORE();

    // run UUT
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_DS18B20_FALURE);
}

void test_temperature_sensor_main_code_converts_fail_neg(void)
{
    TEST_IGNORE();

    // run UUT
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_DS18B20_FALURE);
}

void test_temperature_sensor_main_code_converts_fail_positive(void)
{
    TEST_IGNORE();

    // run UUT
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_DS18B20_FALURE);
}

void test_temperature_sensor_main_code_lcd_write_fail(void)
{
    TEST_IGNORE();

    // run UUT
    temperture_status_t rvalue = temperture_sensor_run();
    TEST_ASSERT_EQUAL_INT(rvalue, TEMP_LCD_FALIURE);
}
