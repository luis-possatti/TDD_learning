#include "LedDriver.h"

/* internal variables */
static uint16_t *led_address_register;

enum {
    ALL_LEDS_ON  = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};
static uint16_t leds_image;

/* Internal function prototypes and definitions*/

static uint16_t convert_led_index_to_bit(uint8_t index);

static uint16_t convert_led_index_to_bit(uint8_t index)
{
    return (uint16_t) (1 << (index - 1));
}



/*
************************************************** 
* Public functions definitions 
**************************************************
*/


void LedDriver_Creator(uint16_t *led_address)
{
    led_address_register = led_address;
    leds_image = ~ALL_LEDS_ON;
    *led_address_register = leds_image;

}


void LedDriver_TurnOn(uint8_t led_index)
{
    if((led_index <= 16) && (led_index >= 1))
    {
        leds_image |= convert_led_index_to_bit(led_index);
        *led_address_register = leds_image;
    }
}

void LedDriver_TurnOff(uint8_t led_index)
{
    if((led_index <= 16) && (led_index >= 1))
    {
        leds_image &= ~convert_led_index_to_bit(led_index);
        *led_address_register = leds_image;
    }
}


void LedDriver_TurnAllOn(void)
{
    leds_image = (uint16_t) ALL_LEDS_ON;
    *led_address_register = leds_image;
}


void LedDriver_TurnAllOff(void)
{
    leds_image = (uint16_t) ALL_LEDS_OFF;
    *led_address_register = leds_image;
}

bool LedDriver_IsOn(uint8_t led_index)
{
    if(leds_image & convert_led_index_to_bit(led_index))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LedDriver_IsOff(uint8_t led_index)
{
    return !LedDriver_IsOn(led_index);
}