#include <stdint.h>
#include <stdbool.h>


void LedDriver_Creator(uint16_t *led_address);
void LedDriver_TurnOn(uint8_t led_index);
void LedDriver_TurnOff(uint8_t led_index);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnAllOff(void);
bool LedDriver_IsOn(uint8_t led_index);
bool LedDriver_IsOff(uint8_t led_index);
