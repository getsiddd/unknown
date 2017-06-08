/*
 * WeightX.cpp
 *
 * Created: 5/31/2017 7:14:53 PM
 * Author : hp user
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#include "HX711.h"
#include "eeprom_WeightX.h"

void all_interrupt_services(){
	GICR = 1<<INT0 | 1<<INT1;
	MCUCR = 1<<ISC01 | 1<<ISC00 | 1<<ISC11 | 1<<ISC10;
	sei();
}

EEPROM_WEIGHTX eeprom;
double weight;
float calibration;
uint8_t decimal;
double tare_point;
bool tare = false, mode = false, mr = false, mp = false;

int main(void)
{	
	all_interrupt_services();
    HX711_init(128);
	calibration = eeprom.read_calibration();
	decimal = eeprom.read_decimal();
	for(int i=0;i<10;i++){
		HX711_read_average(5);
	}
	HX711_tare(10);
	tare_point = HX711_get_offset();
	HX711_set_scale(calibration);
	
    while(1) 
    {
		
    }
}

ISR(INT0_vect){
	mode = !mode;
}

ISR(INT1_vect){
	tare = true;
}

