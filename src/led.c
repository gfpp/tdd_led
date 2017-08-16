#include "led.h"

static uint16_t * ledPort;
static uint16_t LedToPortMask(uint8_t );

void LedInit(uint16_t * port)
{
  ledPort = port;
  *port = 0x0000;
}

void LedOn(uint8_t led)
{
  *ledPort |= LedToPortMask(led);
}

void LedOff(uint8_t led)
{
  *ledPort &= ~LedToPortMask(led);
}

void LedOnAll(void)
{
  *ledPort = 0xFFFF;
}

void LedOffAll(void)
{
  *ledPort = 0x0000;
}

uint8_t LedStatus(uint8_t led)
{
  uint16_t ledStatus = *ledPort & LedToPortMask(led);
  ledStatus = ledStatus >> (led-1);
  return (uint8_t)(ledStatus);
}

static uint16_t LedToPortMask(uint8_t led)
{
  return (1 << (led -1));
}

