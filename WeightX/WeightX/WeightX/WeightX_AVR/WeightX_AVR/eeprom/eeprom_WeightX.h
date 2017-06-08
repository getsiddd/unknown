/*
 * eeprom_WeightX.h
 *
 * Created: 4/26/2017 10:23:21 PM
 *  Author: hp user
 */ 


#ifndef EEPROM_WEIGHTX_H_
#define EEPROM_WEIGHTX_H_

#include <avr/eeprom.h>
#include "scale.h"

class EEPROM_WEIGHTX{
	private:
	uint8_t units = UNITS_KG;
	float calibration = 0.0;
	float tare_point = 0.0;
	uint8_t decimal_places = 0;
	uint8_t average_amount = 10;
	uint8_t serial_trigger = 0;
	char wireless_pass[16];
	public:
	void write_units(uint8_t units);
	uint8_t read_units();
	void write_calibration(float calibration);
	float read_calibration();
	void write_tare(float tare_point);
	float read_tare();
	void write_decimal(uint8_t decimal);
	uint8_t read_decimal();
	void write_average_amount(uint8_t average_amount);
	uint8_t read_average_amount();
	void write_serial_trigger(float tare_point);
	float read_serial_trigger();
	void write_wireless_pass(char wireless[16]);
	char* read_wireless_pass();
};

#endif /* EEPROM_WEIGHTX_H_ */