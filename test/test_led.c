#include "led.h"
#include "unity.h"
#include <stdint.h>

static uint16_t ledPort;

void setUp(void)
{
  LedInit(&ledPort);
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

void test_LedOff(void)
{
  LedOn(1);
  LedOff(1);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledPort);
}

void testLedsOn(void)
{
  ledPort = 0x0000;
  LedOn(8); /* 0x0080 */
  LedOn(9); /* 0x0100 */
  TEST_ASSERT_EQUAL_HEX16(0x0180, ledPort);
}

