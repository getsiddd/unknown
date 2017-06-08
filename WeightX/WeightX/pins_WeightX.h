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

#define BATTERY_PORT           PORTA                           
#define BATTERY_DDR            DDRA                            
#define BATTERY_INPUT          PINA                            
#define BATTERY_PIN            PA0                             
#define BATTERY_READ           (BATTERY_INPUT & (1<<BATTERY_PIN))    
#define BATTERY_SET_HIGH       BATTERY_PORT |= (1<<BATTERY_PIN)
#define BATTERY_SET_LOW        BATTERY_PORT &= ~(1<<BATTERY_PIN)
#define BATTERY_SET_INPUT      BATTERY_DDR &= ~(1<<BATTERY_PIN); BATTERY_SET_HIGH
#define BATTERY_SET_OUTPUT     BATTERY_DDR |= (1<<BATTERY_PIN);  BATTERY_SET_LOW

#define DATA_DISPLAY_PORT           PORTA
#define DATA_DISPLAY_DDR            DDRA
#define DATA_DISPLAY_INPUT          PINA
#define DATA_DISPLAY_PIN            PA1
#define DATA_DISPLAY_READ           (DATA_DISPAY_INPUT & (1<<DATA_DISPAY_PIN))
#define DATA_DISPLAY_SET_HIGH       DATA_DISPAY_PORT |= (1<<DATA_DISPAY_PIN)
#define DATA_DISPLAY_SET_LOW        DATA_DISPAY_PORT &= ~(1<<DATA_DISPAY_PIN)
#define DATA_DISPLAY_SET_INPUT      DATA_DISPAY_DDR &= ~(1<<DATA_DISPAY_PIN); DATA_DISPAY_SET_HIGH
#define DATA_DISPLAY_SET_OUTPUT     DATA_DISPAY_DDR |= (1<<DATA_DISPAY_PIN);  DATA_DISPAY_SET_LOW

#define CLOCK_DISPLAY_PORT           PORTA
#define CLOCK_DISPLAY_DDR            DDRA
#define CLOCK_DISPLAY_INPUT          PINA
#define CLOCK_DISPLAY_PIN            PA2
#define CLOCK_DISPLAY_READ           (CLOCK_DISPLAY_INPUT & (1<<CLOCK_DISPLAY_PIN))
#define CLOCK_DISPLAY_SET_HIGH       CLOCK_DISPLAY_PORT |= (1<<CLOCK_DISPLAY_PIN)
#define CLOCK_DISPLAY_SET_LOW        CLOCK_DISPLAY_PORT &= ~(1<<CLOCK_DISPLAY_PIN)
#define CLOCK_DISPLAY_SET_INPUT      CLOCK_DISPLAY_DDR &= ~(1<<CLOCK_DISPLAY_PIN); CLOCK_DISPLAY_SET_HIGH
#define CLOCK_DISPLAY_SET_OUTPUT     CLOCK_DISPLAY_DDR |= (1<<CLOCK_DISPLAY_PIN);  CLOCK_DISPLAY_SET_LOW

#define ENABLE_DISPLAY_PORT           PORTA
#define ENABLE_DISPLAY_DDR            DDRA
#define ENABLE_DISPLAY_INPUT          PINA
#define ENABLE_DISPLAY_PIN            PA2
#define ENABLE_DISPLAY_READ           (ENABLE_DISPLAY_INPUT & (1<<ENABLE_DISPLAY_PIN))
#define ENABLE_DISPLAY_SET_HIGH       ENABLE_DISPLAY_PORT |= (1<<ENABLE_DISPLAY_PIN)
#define ENABLE_DISPLAY_SET_LOW        ENABLE_DISPLAY_PORT &= ~(1<<ENABLE_DISPLAY_PIN)
#define ENABLE_DISPLAY_SET_INPUT      ENABLE_DISPLAY_DDR &= ~(1<<ENABLE_DISPLAY_PIN); ENABLE_DISPLAY_SET_HIGH
#define ENABLE_DISPLAY_SET_OUTPUT     ENABLE_DISPLAY_DDR |= (1<<ENABLE_DISPLAY_PIN);  ENABLE_DISPLAY_SET_LOW

#define ACTIVATOR_DISPLAY_PORT           PORTC
#define ACTIVATOR_DISPLAY_DDR            DDRC
#define ACTIVATOR_DISPLAY_INPUT          PINC
#define ACTIVATOR_DISPLAY_PIN            PC2
#define ACTIVATOR_DISPLAY_READ           (ACTIVATOR_DISPLAY_INPUT & (1<<ACTIVATOR_DISPLAY_PIN))
#define ACTIVATOR_DISPLAY_SET_HIGH       ACTIVATOR_DISPLAY_PORT |= (1<<ACTIVATOR_DISPLAY_PIN)
#define ACTIVATOR_DISPLAY_SET_LOW        ACTIVATOR_DISPLAY_PORT &= ~(1<<ACTIVATOR_DISPLAY_PIN)
#define ACTIVATOR_DISPLAY_SET_INPUT      ACTIVATOR_DISPLAY_DDR &= ~(1<<ACTIVATOR_DISPLAY_PIN); ACTIVATOR_DISPLAY_SET_HIGH
#define ACTIVATOR_DISPLAY_SET_OUTPUT     ACTIVATOR_DISPLAY_DDR |= (1<<ACTIVATOR_DISPLAY_PIN);  ACTIVATOR_DISPLAY_SET_LOW

#define PD_SCK1_PORT         PORTC                           // Power Down and Serial Clock Input Port
#define PD_SCK1_DDR          DDRC                            // Power Down and Serial Clock DDR
#define PD_SCK1_PIN          PC4                             // Power Down and Serial Clock Pin
#define PD_SCK1_SET_OUTPUT   PD_SCK_DDR |= (1<<PD_SCK_PIN)
#define PD_SCK1_SET_HIGH     PD_SCK_PORT |= (1<<PD_SCK_PIN)
#define PD_SCK1_SET_LOW      PD_SCK_PORT &= ~(1<<PD_SCK_PIN)

#define DOUT1_PORT           PORTC                           // Serial Data Output Port
#define DOUT1_DDR            DDRC                            // Serial Data Output DDR
#define DOUT1_INPUT          PINC                            // Serial Data Output Input
#define DOUT1_PIN            PC3                             // Serial Data Output Pin
#define DOUT1_READ           (DOUT1_INPUT & (1<<DOUT1_PIN))    // Serial Data Output Read Pin
#define DOUT1_SET_HIGH       DOUT1_PORT |= (1<<DOUT1_PIN)
#define DOUT1_SET_LOW        DOUT1_PORT &= ~(1<<DOUT1_PIN)
#define DOUT1_SET_INPUT      DOUT1_DDR &= ~(1<<DOUT1_PIN); DOUT1_SET_HIGH
#define DOUT1_SET_OUTPUT     DOUT1_DDR |= (1<<DOUT1_PIN);  DOUT1_SET_LOW

#define BUTTON1_PORT           PORTD                           // Serial Data Output Port
#define BUTTON1_DDR            DDRD                            // Serial Data Output DDR
#define BUTTON1_INPUT          PIND                            // Serial Data Output Input
#define BUTTON1_PIN            PD2                             // Serial Data Output Pin
#define BUTTON1_READ           (BUTTON1_INPUT & (1<<BUTTON1_PIN))    // Serial Data Output Read Pin
#define BUTTON1_SET_HIGH       BUTTON1_PORT |= (1<<BUTTON1_PIN)
#define BUTTON1_SET_LOW        BUTTON1_PORT &= ~(1<<BUTTON1_PIN)
#define BUTTON1_SET_INPUT      BUTTON1_DDR &= ~(1<<BUTTON1_PIN); BUTTON1_SET_HIGH
#define BUTTON1_SET_OUTPUT     BUTTON1_DDR |= (1<<BUTTON1_PIN);  BUTTON1_SET_LOW

#define BUTTON2_PORT           PORTD                           // Serial Data Output Port
#define BUTTON2_DDR            DDRD                            // Serial Data Output DDR
#define BUTTON2_INPUT          PIND                            // Serial Data Output Input
#define BUTTON2_PIN            PD3                             // Serial Data Output Pin
#define BUTTON2_READ           (BUTTON2_INPUT & (1<<BUTTON2_PIN))    // Serial Data Output Read Pin
#define BUTTON2_SET_HIGH       BUTTON2_PORT |= (1<<BUTTON2_PIN)
#define BUTTON2_SET_LOW        BUTTON2_PORT &= ~(1<<BUTTON2_PIN)
#define BUTTON2_SET_INPUT      BUTTON2_DDR &= ~(1<<BUTTON2_PIN); BUTTON2_SET_HIGH
#define BUTTON2_SET_OUTPUT     BUTTON2_DDR |= (1<<BUTTON2_PIN);  BUTTON2_SET_LOW

#define BUTTON3_PORT           PORTD                           // Serial Data Output Port
#define BUTTON3_DDR            DDRD                            // Serial Data Output DDR
#define BUTTON3_INPUT          PIND                            // Serial Data Output Input
#define BUTTON3_PIN            PD4                             // Serial Data Output Pin
#define BUTTON3_READ           (BUTTON3_INPUT & (1<<BUTTON3_PIN))    // Serial Data Output Read Pin
#define BUTTON3_SET_HIGH       BUTTON3_PORT |= (1<<BUTTON3_PIN)
#define BUTTON3_SET_LOW        BUTTON3_PORT &= ~(1<<BUTTON3_PIN)
#define BUTTON3_SET_INPUT      BUTTON3_DDR &= ~(1<<BUTTON3_PIN); BUTTON3_SET_HIGH
#define BUTTON3_SET_OUTPUT     BUTTON3_DDR |= (1<<BUTTON3_PIN);  BUTTON3_SET_LOW

#define BUTTON4_PORT           PORTD                           // Serial Data Output Port
#define BUTTON4_DDR            DDRD                            // Serial Data Output DDR
#define BUTTON4_INPUT          PIND                            // Serial Data Output Input
#define BUTTON4_PIN            PD4                             // Serial Data Output Pin
#define BUTTON4_READ           (BUTTON4_INPUT & (1<<BUTTON4_PIN))    // Serial Data Output Read Pin
#define BUTTON4_SET_HIGH       BUTTON4_PORT |= (1<<BUTTON4_PIN)
#define BUTTON4_SET_LOW        BUTTON4_PORT &= ~(1<<BUTTON4_PIN)
#define BUTTON4_SET_INPUT      BUTTON4_DDR &= ~(1<<BUTTON4_PIN); BUTTON4_SET_HIGH
#define BUTTON4_SET_OUTPUT     BUTTON4_DDR |= (1<<BUTTON4_PIN);  BUTTON4_SET_LOW

#define CE_NRF_PORT           PORTB                           // Serial Data Output Port
#define CE_NRF_DDR            DDRB                            // Serial Data Output DDR
#define CE_NRF_INPUT          PINB                            // Serial Data Output Input
#define CE_NRF_PIN            PB3                             // Serial Data Output Pin
#define CE_NRF_READ           (CE_NRF_INPUT & (1<<CE_NRF_PIN))    // Serial Data Output Read Pin
#define CE_NRF_SET_HIGH       CE_NRF_PORT |= (1<<CE_NRF_PIN)
#define CE_NRF_SET_LOW        CE_NRF_PORT &= ~(1<<CE_NRF_PIN)
#define CE_NRF_SET_INPUT      CE_NRF_DDR &= ~(1<<CE_NRF_PIN); CE_NRF_SET_HIGH
#define CE_NRF_SET_OUTPUT     CE_NRF_DDR |= (1<<CE_NRF_PIN);  CE_NRF_SET_LOW

#define CE_MEMORY_PORT           PORTB                           // Serial Data Output Port
#define CE_MEMORY_DDR            DDRB                            // Serial Data Output DDR
#define CE_MEMORY_INPUT          PINB                            // Serial Data Output Input
#define CE_MEMORY_PIN            PB1                             // Serial Data Output Pin
#define CE_MEMORY_READ           (CE_MEMORY_INPUT & (1<<CE_MEMORY_PIN))    // Serial Data Output Read Pin
#define CE_MEMORY_SET_HIGH       CE_MEMORY_PORT |= (1<<CE_MEMORY_PIN)
#define CE_MEMORY_SET_LOW        CE_MEMORY_PORT &= ~(1<<CE_MEMORY_PIN)
#define CE_MEMORY_SET_INPUT      CE_MEMORY_DDR &= ~(1<<CE_MEMORY_PIN); CE_MEMORY_SET_HIGH
#define CE_MEMORY_SET_OUTPUT     CE_MEMORY_DDR |= (1<<CE_MEMORY_PIN);  CE_MEMORY_SET_LOW

#define NRF_INT_PORT           PORTB                           // Serial Data Output Port
#define NRF_INT_DDR            DDRB                            // Serial Data Output DDR
#define NRF_INT_INPUT          PINB                            // Serial Data Output Input
#define NRF_INT_PIN            PB2                             // Serial Data Output Pin
#define NRF_INT_READ           (NRF_INT_INPUT & (1<<NRF_INT_PIN))    // Serial Data Output Read Pin
#define NRF_INT_SET_HIGH       NRF_INT_PORT |= (1<<NRF_INT_PIN)
#define NRF_INT_SET_LOW        NRF_INT_PORT &= ~(1<<NRF_INT_PIN)
#define NRF_INT_SET_INPUT      NRF_INT_DDR &= ~(1<<NRF_INT_PIN); NRF_INT_SET_HIGH
#define NRF_INT_SET_OUTPUT     NRF_INT_DDR |= (1<<NRF_INT_PIN);  NRF_INT_SET_LOW