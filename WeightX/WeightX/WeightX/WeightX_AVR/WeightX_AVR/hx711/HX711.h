#ifndef HX711_h
#define HX711_h

#include "pins_hx711.h"    

class HX711
{
	public:
	void init(uint8_t gain);
	int is_ready(void);
	void set_gain(uint8_t gain);
	uint32_t read(void);
	uint32_t read_average(uint8_t times);
	double get_value(uint8_t times);
	float get_units(uint8_t times);
	void tare(uint8_t times);
	void set_scale(float scale);
	float get_scale(void);
	void set_offset(double offset);
	double get_offset(void);
	void power_down(void);
	void power_up(void);
	private:	
	uint8_t GAIN;                   // amplification factor
	double OFFSET;                  // used for tare weight
	float SCALE;                      // used to return weight in grams, kg, ounces, whatever
};
#endif /* HX711_h */

