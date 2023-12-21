// test_ds18b20.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "unity.h"
#include "ds18b20.h"

void setUp(void)
{
    bool okay = ds18b20_initialise(R12);
    TEST_ASSERT_TRUE(okay);
}

void tearDown(void)
{
}

void test_ds18b20_reset_value(void)
{
    int16_t raw = 0x0550;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(85.0f, actual);
}

void test_ds18b20_zero(void)
{
    int16_t raw = 0x0000;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, actual);
}

void test_ds18b20_most_valid_positive(void)
{
    int16_t raw = 0x07D0;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(125.0f, actual);
}

void test_ds18b20_most_valid_negative(void)
{
    int16_t raw = 0xFC90;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(-55.0f, actual);
}

void test_ds18b20_smallest_fraction(void)
{
    int16_t raw = 0x0001;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.0625f, actual);
}

void test_ds18b20_smallest_fraction_R9(void)
{
    int16_t raw = 0x000F;
    bool okay = ds18b20_initialise(R9);
    TEST_ASSERT_TRUE(okay);
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.875f, actual);
}

void test_ds18b20_one_eighth_fraction(void)
{
    int16_t raw = 0x0002;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.125f, actual);
}

void test_ds18b20_one_eighth_fraction_R10(void)
{
    int16_t raw = 0x000F;
    bool okay = ds18b20_initialise(R10);
    TEST_ASSERT_TRUE(okay);
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.75f, actual);
}

void test_ds18b20_one_quarter_fraction(void)
{
    int16_t raw = 0x0004;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.25f, actual);
}

void test_ds18b20_one_quarter_fraction_R11(void)
{
    int16_t raw = 0x000F;
    bool okay = ds18b20_initialise(R11);
    TEST_ASSERT_TRUE(okay);
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.5f, actual);
}

void test_ds18b20_illegal_initializer(void)
{
    int16_t raw = 0x000F;
    bool okay = ds18b20_initialise(R12+1);
    TEST_ASSERT_FALSE(okay);
}

// What sould be the outcome of anything > +125C ?
void test_ds18b20_max_positive(void)
{
    TEST_IGNORE();
    int16_t raw = 0x7FFF;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, actual);
}

// What sould be the outcome of anything < -55C ?
void test_ds18b20_max_negative(void)
{
    TEST_IGNORE();
    int16_t raw = 0x8000;
    float actual = ds18b20_convert(raw);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, actual);
}
