#include "led.h"

static uint16_t * ledPort;

void LedInit(uint16_t * port)
{
  ledPort = port;
  *port = 0x0000;
}

void LedOn(uint8_t led)
{
  *ledPort = 0x0001;
}
