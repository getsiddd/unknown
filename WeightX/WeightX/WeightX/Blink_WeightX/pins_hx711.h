
#define PD_SCK_PORT         PORTA                           // Power Down and Serial Clock Input Port
#define PD_SCK_DDR          DDRA                            // Power Down and Serial Clock DDR
#define PD_SCK_PIN          PA5                             // Power Down and Serial Clock Pin
#define PD_SCK_SET_OUTPUT   PD_SCK_DDR |= (1<<PD_SCK_PIN)
#define PD_SCK_SET_HIGH     PD_SCK_PORT |= (1<<PD_SCK_PIN)
#define PD_SCK_SET_LOW      PD_SCK_PORT &= ~(1<<PD_SCK_PIN)

#define DOUT_PORT           PORTA                           // Serial Data Output Port
#define DOUT_DDR            DDRA                            // Serial Data Output DDR
#define DOUT_INPUT          PINA                            // Serial Data Output Input
#define DOUT_PIN            PA4                             // Serial Data Output Pin
#define DOUT_READ           (DOUT_INPUT & (1<<DOUT_PIN))    // Serial Data Output Read Pin
#define DOUT_SET_HIGH       DOUT_PORT |= (1<<DOUT_PIN)  
#define DOUT_SET_LOW        DOUT_PORT &= ~(1<<DOUT_PIN) 
#define DOUT_SET_INPUT      DOUT_DDR &= ~(1<<DOUT_PIN); DOUT_SET_HIGH
#define DOUT_SET_OUTPUT     DOUT_DDR |= (1<<DOUT_PIN);  DOUT_SET_LOW


