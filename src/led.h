#ifndef _LED_H
#define _LED_H

#include <stdint.h>

void LedInit(uint16_t * );
void LedOn(uint8_t );
void LedOff(uint8_t );
void LedOnAll(void);
void LedOffAll(void);
uint8_t LedStatus(uint8_t );

#endif
