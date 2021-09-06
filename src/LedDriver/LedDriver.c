#include "LedDriver.h"

/* internal variables, types and prototypes */
static uint16_t *led_address_register;

enum {
    ALL_LEDS_ON  = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static uint16_t leds_image;


static uint16_t convert_led_index_to_bit(uint8_t index);
static void update_Hardware(void);
static bool valid_index(uint8_t index);
static void set_led(uint8_t index);
static void clear_led(uint8_t index);



/*
************************************************** 
* Public functions definitions - INIT
**************************************************
*/


void LedDriver_Creator(uint16_t *led_address)
{
    led_address_register = led_address;
    leds_image = ~ALL_LEDS_ON;
    update_Hardware();

}


void LedDriver_TurnOn(uint8_t led_index)
{
    if(valid_index(led_index))
    {
        set_led(led_index);
        update_Hardware();
    }
}

void LedDriver_TurnOff(uint8_t led_index)
{
    if(valid_index(led_index))
    {
        clear_led(led_index);
        update_Hardware();
    }
}


void LedDriver_TurnAllOn(void)
{
    leds_image = (uint16_t) ALL_LEDS_ON;
    update_Hardware();
}


void LedDriver_TurnAllOff(void)
{
    leds_image = (uint16_t) ALL_LEDS_OFF;
    update_Hardware();
    
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


/*
************************************************** 
* Public functions definitions - END
**************************************************
*/







/*
************************************************** 
* Private functions definitions - INIT
**************************************************
*/



static uint16_t convert_led_index_to_bit(uint8_t index)
{
    return (uint16_t) (1 << (index - 1));
}


static void update_Hardware(void)
{
    *led_address_register = leds_image;
}



static bool valid_index(uint8_t index)
{
    bool result;
    if((index <= 16) && (index >= 1))
    {
        result = true;

    }
    else
    {
        result = false;
    }

    return result;
}



static void set_led(uint8_t index)
{
    leds_image |= convert_led_index_to_bit(index);
}
static void clear_led(uint8_t index)
{
    leds_image &= ~convert_led_index_to_bit(index);
}



/*
************************************************** 
* Private functions definitions - END
**************************************************
*/

