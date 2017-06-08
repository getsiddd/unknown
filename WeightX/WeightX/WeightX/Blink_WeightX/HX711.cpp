#define __USE_C99_MATH

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "HX711.h"

uint8_t GAIN;                   // amplification factor
double OFFSET;                  // used for tare weight
float SCALE;                      // used to return weight in grams, kg, ounces, whatever

void HX711_init(uint8_t gain)
{
    PD_SCK_SET_OUTPUT;
    DOUT_SET_INPUT;

    HX711_set_gain(gain);
    Serial.println("Welcome to WeightX-Program");
}

int HX711_is_ready(void)
{
    return DOUT_READ == 0;
}

void HX711_set_gain(uint8_t gain)
{
  switch (gain)
  {
    case 128:   // channel A, gain factor 128
      GAIN = 1;
      break;
    case 64:    // channel A, gain factor 64
      GAIN = 3;
      break;
    case 32:    // channel B, gain factor 32
      GAIN = 2;
      break;
  }

  PD_SCK_SET_LOW;
  HX711_read();
}

uint32_t HX711_read(void)
{
  // wait for the chip to become ready
    while (!HX711_is_ready());
    unsigned long count; 
    unsigned char i;
 
    DOUT_SET_HIGH;
    PD_SCK_SET_LOW; 
    count=0;
    while(DOUT_READ); 
    for(i=0;i<24;i++)
    { 
        PD_SCK_SET_HIGH; 
        count=count<<1; 
        PD_SCK_SET_LOW; 
        if(DOUT_READ)
            count++; 
    } 
    count = count>>6;
    PD_SCK_SET_HIGH; 
    PD_SCK_SET_LOW; 
    count ^= 0x800000;
    return(count);
}

uint32_t HX711_read_average(uint8_t times)
{
  uint32_t sum = 0;
  for (uint8_t i = 0; i < times; i++)
  {
    sum += HX711_read();
    // TODO: See if yield will work | yield();
  }
  return sum / times;
}

double HX711_get_value(uint8_t times)
{
  return HX711_read_average(times) - OFFSET;
}

float HX711_get_units(uint8_t times)
{
  return HX711_get_value(times) / SCALE;
}

void HX711_tare(uint8_t times)
{
  double sum = HX711_read_average(times);
  HX711_set_offset(sum);
}

void HX711_set_scale(float scale)
{
  SCALE = scale;
}

float HX711_get_scale(void)
{
  return SCALE;
}

void HX711_set_offset(double offset)
{
    OFFSET = offset;
}

double HX711_get_offset(void)
{
  return OFFSET;
}

void HX711_power_down(void)
{
  PD_SCK_SET_LOW;
  PD_SCK_SET_HIGH;
  _delay_us(70);
}

void HX711_power_up(void)
{
  PD_SCK_SET_LOW;
}

