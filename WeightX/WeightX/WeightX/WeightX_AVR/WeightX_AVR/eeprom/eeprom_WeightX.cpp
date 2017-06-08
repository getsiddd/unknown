/*
 * eeprom_WeightX.cpp
 *
 * Created: 4/26/2017 10:23:41 PM
 *  Author: hp user
 */ 

#include "eeprom_WeightX.h"

void EEPROM_WEIGHTX::write_units(uint8_t units){
	eeprom_write_byte((uint8_t *) LOCATION_MASS_UNITS, units);
	units = units;
}

uint8_t EEPROM_WEIGHTX::read_units(){
	return eeprom_read_byte((uint8_t *)LOCATION_MASS_UNITS);
}

void EEPROM_WEIGHTX::write_calibration(float calibration){
	eeprom_write_block((uint8_t *)LOCATION_CALIBRATION_FACTOR_MSB, &calibration, 4);
	calibration = calibration;
}

float EEPROM_WEIGHTX::read_calibration(){
	eeprom_read_block(&calibration, (uint8_t *)LOCATION_CALIBRATION_FACTOR_MSB, 4);
	return calibration;
}

void EEPROM_WEIGHTX::write_tare(float tare_point){
	eeprom_write_block((uint8_t *)LOCATION_TARE_POINT_MSB, &tare_point, 4);
	tare_point = tare_point;
}

float EEPROM_WEIGHTX::read_tare(){
	eeprom_read_block(&tare_point, (uint8_t *)LOCATION_TARE_POINT_MSB, 4);
	return tare_point;
}

void EEPROM_WEIGHTX::write_decimal(uint8_t decimal){
	eeprom_write_byte((uint8_t *) LOCATION_DECIMAL_PLACES, decimal);
	decimal_places = decimal;
}

uint8_t EEPROM_WEIGHTX::read_decimal(){
	return eeprom_read_byte((uint8_t *)LOCATION_DECIMAL_PLACES);
}

void EEPROM_WEIGHTX::write_average_amount(uint8_t average){
	eeprom_write_byte((uint8_t *) LOCATION_AVERAGE_AMOUNT, average);
	average_amount = average;
}

uint8_t EEPROM_WEIGHTX::read_average_amount(){
	return eeprom_read_byte((uint8_t *)LOCATION_AVERAGE_AMOUNT);
}

void EEPROM_WEIGHTX::write_serial_trigger(uint8_t serial){
	eeprom_write_byte((uint8_t *) LOCATION_SERIAL_TRIGGER_ENABLE, serial);
	serial_trigger = serial;
}

uint8_t EEPROM_WEIGHTX::read_serial_trigger(){
	return eeprom_read_byte((uint8_t *)LOCATION_SERIAL_TRIGGER_ENABLE);
}

void EEPROM_WEIGHTX::write_wireless_pass(char wireless[16]){
	eeprom_write_block((uint8_t *)LOCATION_WIRELESS_PASSWORD_MSB, &wireless, 4);
	wireless_pass = wireless;
}

char* EEPROM_WEIGHTX::read_wireless_pass(){
	eeprom_read_block(&wireless_pass, (uint8_t *)LOCATION_WIRELESS_PASSWORD_MSB, 4);
	return wireless_pass;
}