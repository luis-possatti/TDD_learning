#ifndef __LED_DRIVER_H_
#define __LED_DRIVER_H_

#include <stdint.h>
#include <stdbool.h>
#include "RunTimeError.h"


void LedDriver_Creator(uint16_t *led_address);
void LedDriver_TurnOn(int8_t led_index);
void LedDriver_TurnOff(int8_t led_index);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
bool LedDriver_IsOn(int8_t led_index);
bool LedDriver_IsOff(int8_t led_index);


#endif