
#define PD_SCK_PORT         PORTD                           // Power Down and Serial Clock Input Port
#define PD_SCK_DDR          DDRD                            // Power Down and Serial Clock DDR
#define PD_SCK_PIN          PD4                             // Power Down and Serial Clock Pin
#define PD_SCK_SET_OUTPUT   PD_SCK_DDR |= (1<<PD_SCK_PIN)
#define PD_SCK_SET_HIGH     PD_SCK_PORT |= (1<<PD_SCK_PIN)
#define PD_SCK_SET_LOW      PD_SCK_PORT &= ~(1<<PD_SCK_PIN)

#define DOUT_PORT           PORTD                           // Serial Data Output Port
#define DOUT_DDR            DDRD                            // Serial Data Output DDR
#define DOUT_INPUT          PIND                            // Serial Data Output Input
#define DOUT_PIN            PD5                             // Serial Data Output Pin
#define DOUT_READ           (DOUT_INPUT & (1<<DOUT_PIN))    // Serial Data Output Read Pin
#define DOUT_SET_HIGH       DOUT_PORT |= (1<<DOUT_PIN)  
#define DOUT_SET_LOW        DOUT_PORT &= ~(1<<DOUT_PIN) 
#define DOUT_SET_INPUT      DOUT_DDR &= ~(1<<DOUT_PIN); DOUT_SET_HIGH
#define DOUT_SET_OUTPUT     DOUT_DDR |= (1<<DOUT_PIN);  DOUT_SET_LOW


