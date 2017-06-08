/*
 * pins_button.h
 *
 * Created: 4/27/2017 9:12:39 AM
 *  Author: hp user
 */ 


#ifndef PINS_BUTTON_H_
#define PINS_BUTTON_H_

#define MODE_PORT           PORTD                           // Serial Data Output Port
#define MODE_DDR            DDRD                            // Serial Data Output DDR
#define MODE_INPUT          PIND                            // Serial Data Output Input
#define MODE_PIN            PD2                             // Serial Data Output Pin
#define MODE_READ           (MODE_INPUT & (1<<MODE_PIN))    // Serial Data Output Read Pin
#define MODE_SET_HIGH       MODE_PORT |= (1<<MODE_PIN)
#define MODE_SET_LOW        MODE_PORT &= ~(1<<MODE_PIN)
#define MODE_SET_INPUT      MODE_DDR &= ~(1<<MODE_PIN); MODE_SET_HIGH
#define MODE_SET_OUTPUT     MODE_DDR |= (1<<MODE_PIN);  MODE_SET_LOW

#define MR_PORT           PORTD                           // Serial Data Output Port
#define MR_DDR            DDRD                            // Serial Data Output DDR
#define MR_INPUT          PIND                            // Serial Data Output Input
#define MR_PIN            PD4                             // Serial Data Output Pin
#define MR_READ           (MR_INPUT & (1<<MR_PIN))    // Serial Data Output Read Pin
#define MR_SET_HIGH       MR_PORT |= (1<<MR_PIN)
#define MR_SET_LOW        MR_PORT &= ~(1<<MR_PIN)
#define MR_SET_INPUT      MR_DDR &= ~(1<<MR_PIN); MR_SET_HIGH
#define MR_SET_OUTPUT     MR_DDR |= (1<<MR_PIN);  MR_SET_LOW

#define MP_PORT           PORTD                           // Serial Data Output Port
#define MP_DDR            DDRD                            // Serial Data Output DDR
#define MP_INPUT          PIND                            // Serial Data Output Input
#define MP_PIN            PD5                             // Serial Data Output Pin
#define MP_READ           (MP_INPUT & (1<<MP_PIN))    // Serial Data Output Read Pin
#define MP_SET_HIGH       MP_PORT |= (1<<MP_PIN)
#define MP_SET_LOW        MP_PORT &= ~(1<<MP_PIN)
#define MP_SET_INPUT      MP_DDR &= ~(1<<MP_PIN); MP_SET_HIGH
#define MP_SET_OUTPUT     MP_DDR |= (1<<MP_PIN);  MP_SET_LOW

#define TARE_PORT           PORTD                           // Serial Data Output Port
#define TARE_DDR            DDRD                            // Serial Data Output DDR
#define TARE_INPUT          PIND                            // Serial Data Output Input
#define TARE_PIN            PD3                             // Serial Data Output Pin
#define TARE_READ           (TARE_INPUT & (1<<TARE_PIN))    // Serial Data Output Read Pin
#define TARE_SET_HIGH       TARE_PORT |= (1<<TARE_PIN)
#define TARE_SET_LOW        TARE_PORT &= ~(1<<TARE_PIN)
#define TARE_SET_INPUT      TARE_DDR &= ~(1<<TARE_PIN); TARE_SET_HIGH
#define TARE_SET_OUTPUT     TARE_DDR |= (1<<TARE_PIN);  TARE_SET_LOW

#endif /* PINS_BUTTON_H_ */