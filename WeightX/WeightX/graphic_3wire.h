/*
 * graphic_3wire.h
 *
 * Created: 6/2/2017 8:49:35 PM
 *  Author: hp user
 */ 


#ifndef GRAPHIC_3WIRE_H_
#define GRAPHIC_3WIRE_H_

#include <avr/io.h>
#include <util/delay.h>

#define MAX_LENGTH  128
#define MAX_BREADTH 64

#include "pins_WeightX.h"

void graphic_init();
void graphic_write_string(char *string, int pos_X, int pos_Y);
void graphic_write_number(int number, int pox_X, int pos_Y);
void graphic_write_command(char command);
void graphic_clear();

#endif /* GRAPHIC_3WIRE_H_ */