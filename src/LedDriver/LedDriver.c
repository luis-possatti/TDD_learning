#include "LedDriver.h"

static uint16_t *led_address_register;

void LedDriver_Creator(uint16_t *led_address)
{
    led_address_register = led_address;
    *led_address = 0;
}


void LedDriver_TurnOn(uint8_t led_index)
{
    *led_address_register = 1;   
}