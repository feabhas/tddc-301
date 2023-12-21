// test_ring_buffer.c
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "unity.h"

#include "ring_buffer.h"

void setUp(void)
{
    TEST_ASSERT(buffer_init());
}

void tearDown(void)
{
}

void test_ring_buffer_init(void)
{
    TEST_ASSERT_TRUE(buffer_is_empty());
    TEST_ASSERT_FALSE(buffer_is_full());
    TEST_ASSERT_EQUAL_INT(0, buffer_count());
}

void test_ring_buffer_add_first(void)
{
    TEST_ASSERT(buffer_add(42));
    TEST_ASSERT_FALSE(buffer_is_empty());
    TEST_ASSERT_FALSE(buffer_is_full());
    TEST_ASSERT_EQUAL_INT(1, buffer_count());
}

void test_ring_buffer_read_one(void)
{
    buffer_add(42);
    int rvalue = 0;
    bool result = buffer_get(&rvalue);
    TEST_ASSERT_TRUE(result);

    TEST_ASSERT_TRUE(buffer_is_empty());
    TEST_ASSERT_FALSE(buffer_is_full());
    TEST_ASSERT_EQUAL_INT(0, buffer_count());

    TEST_ASSERT_EQUAL_INT(42, rvalue);

}

void test_ring_buffer_read_from_empty(void)
{
    int rvalue = 0;
    bool result = buffer_get(&rvalue);
    TEST_ASSERT_FALSE(result);

    TEST_ASSERT_TRUE(buffer_is_empty());
    TEST_ASSERT_FALSE(buffer_is_full());
    TEST_ASSERT_EQUAL_INT(0, buffer_count());

    TEST_ASSERT_EQUAL_INT(0, rvalue);
}

void test_ring_buffer_capacity(void)
{
    TEST_ASSERT_EQUAL_INT(16, buffer_capacity());
}

void test_ring_buffer_fill_to_capacity(void)
{
    unsigned capacity = buffer_capacity();
    for(unsigned i = 1; i < capacity; ++i){
        TEST_ASSERT(buffer_add(i));
        TEST_ASSERT_FALSE(buffer_is_full());
        TEST_ASSERT_EQUAL_INT(i, buffer_count());
    }
    TEST_ASSERT(buffer_add(42));
    TEST_ASSERT_TRUE(buffer_is_full());
    TEST_ASSERT_EQUAL_INT(buffer_capacity(), buffer_count());
}

void test_ring_buffer_fill_to_over_capacity(void)
{
    test_ring_buffer_fill_to_capacity();
    TEST_ASSERT_FALSE(buffer_add(42));
}

void test_buffer_write_then_read_multiple(void)
{
    TEST_ASSERT(buffer_add(42));
    TEST_ASSERT(buffer_add(24));
    int rvalue = 0;
    bool result = buffer_get(&rvalue);
    TEST_ASSERT_TRUE(result);

    TEST_ASSERT_FALSE(buffer_is_empty());
    TEST_ASSERT_EQUAL_INT(1, buffer_count());
    TEST_ASSERT_EQUAL_INT(42, rvalue);
}

void test_ring_buffer_fill_to_capacity_read_to_empty(void)
{
    unsigned capacity = buffer_capacity();
    for(unsigned i = 1; i <= capacity; ++i){
        TEST_ASSERT(buffer_add(i));
        TEST_ASSERT_EQUAL_INT(i, buffer_count());
    }
    TEST_ASSERT_TRUE(buffer_is_full());
    for(unsigned i = 1; i <= capacity; ++i){
        int rvalue = 0;
        bool result = buffer_get(&rvalue);
        TEST_ASSERT_TRUE(result);
        TEST_ASSERT_EQUAL_INT(i, rvalue);
        TEST_ASSERT_EQUAL_INT(buffer_capacity() - i, buffer_count());
    }
    TEST_ASSERT_TRUE(buffer_is_empty());
}

void test_buffer_wrap_around(void)
{
    unsigned capacity = buffer_capacity();
    for(unsigned i = 1; i <= capacity; ++i){
        TEST_ASSERT(buffer_add(i));
    }
    unsigned half_capacity = capacity/2;
    for(unsigned i = 1; i <= half_capacity; ++i){
        int rvalue = 0;
        bool result = buffer_get(&rvalue);
        TEST_ASSERT_TRUE(result);
    }

    // fill again
    while(buffer_add(-1));

    while(!buffer_is_empty()){
        int rvalue = 0;
        bool result = buffer_get(&rvalue);
        TEST_ASSERT_TRUE(result);
    }

}
