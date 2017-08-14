#include "led.h"
#include "unity.h"
#include <stdint.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_LedsOffAfterCreate(void)
{
/*  TEST_FAIL_MESSAGE("Empezamos");*/
  uint16_t ledPort = 0xFFFF;
  LedInit(&ledPort);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledPort);
}

void test_LedOn(void)
{
  LedOn(1);
  TEST_ASSERT_EQUAL_HEX16(0x0001, ledPort);
}

