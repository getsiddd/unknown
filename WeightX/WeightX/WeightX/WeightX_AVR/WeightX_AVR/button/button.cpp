/*
 * button.cpp
 *
 * Created: 4/27/2017 9:56:25 AM
 *  Author: hp user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void button_init(void){
	mp = false;
	mode = false;
	tare_button = false;
	mr = false;

	MODE_SET_INPUT;
	TARE_SET_INPUT;
	MP_SET_INPUT;
	MR_SET_INPUT;
	
	GICR|=(1<<INT0)|(1<<INT1);
	MCUCR|=(1<<ISC01);
	
	TIMSK = (1<<TOIE0);
	TCNT0 = 0x00;
	TCCR0 = (1<<CS02) | (1<<CS00);
}

ISR(TIMER0_OVF_vect){
	if(MP_READ == 0){
		mp = true;
	}
	if(MR_READ == 0){
		mr = true;
	}
}

ISR(INT0_vect){
	mode = true;
}

ISR(INT1_vect){
	tare_button = true;
}

