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

void test_LedsOn(void)
{
  ledPort = 0x0000;
  LedOn(8); /* 0x0080 */
  LedOn(9); /* 0x0100 */
  TEST_ASSERT_EQUAL_HEX16(0x0180, ledPort);
}

void test_LedsOff(void)
{
  ledPort = 0xFFFF;
  LedOff(8);
  LedOff(9);
  TEST_ASSERT_EQUAL_HEX16(0xFE7F, ledPort);
}

void test_LedOnAll(void)
{
  ledPort = 0x0000;
  LedOnAll();
  TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledPort);
}

void test_LedOffAll(void)
{
  ledPort = 0xFFFF;
  LedOffAll();
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledPort);
}

void test_LedStatus1On(void)
{
  LedOn(1); /* Turn on LED 1 */
  TEST_ASSERT_EQUAL_UINT8(1, LedStatus(1));
}

void test_LedStatus1Off(void)
{
  LedOff(1); /* Turn off LED 1 */
  TEST_ASSERT_EQUAL_UINT8(0, LedStatus(1));
}

void test_LedStatus8On(void)
{
  LedOn(8);
  TEST_ASSERT_EQUAL_UINT8(1, LedStatus(8));
}

void test_LedStatus8Off(void)
{
  LedOff(8);
  TEST_ASSERT_EQUAL_UINT8(0, LedStatus(8));
}
