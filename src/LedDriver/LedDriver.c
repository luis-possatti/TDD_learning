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
    *led_address = (uint16_t) ~ALL_LEDS_ON;
}


void LedDriver_TurnOn(uint8_t led_index)
{
    *led_address_register |= convert_led_index_to_bit(led_index);   
}

void LedDriver_TurnOff(uint8_t led_index)
{
    *led_address_register &= ~convert_led_index_to_bit(led_index);
}


void LedDriver_TurnAllOn(void)
{
    *led_address_register = (uint16_t) ALL_LEDS_ON;
}


void LedDriver_TurnAllOff(void)
{
    *led_address_register = (uint16_t) ~ALL_LEDS_ON;
}