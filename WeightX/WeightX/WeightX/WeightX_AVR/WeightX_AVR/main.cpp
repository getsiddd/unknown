#include <avr/interrupt.h>
#include <avr/io.h>
#include "hx711/HX711.h"
#include "eeprom/eeprom_WeightX.h"
#include "button/button.h"

int main(void)
{
	twi_init();
	sei();
	return 0;	
}