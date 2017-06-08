/*
 * graphic_3wire.cpp
 *
 * Created: 6/2/2017 8:50:03 PM
 *  Author: hp user
 */ 

// Order of Graphic LCD pin outs:-
// leave, CS2, CS1, DB7, DB6, DB5, DB4, DB3, leave, DB2, DB1, DB0, R/W, C/D, QG, QH

#include "graphic_3wire.h"

unsigned char Decimal_Array[5];
unsigned char set_xaddr;
unsigned char set_yaddr;
const unsigned char *data_ptr;
unsigned char line_limit=0;

void send_nibble(int data){
	int i;
	DATA_DISPLAY_SET_LOW;
	CLOCK_DISPLAY_SET_LOW;
	for(i = 0; i<=15; i++)
	{
		CLOCK_DISPLAY_SET_HIGH;
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		CLOCK_DISPLAY_SET_LOW;
	}
	
	for(i = 0; i<=15; i++)
	{
		if(data & 0x01)
		{
			DATA_DISPLAY_SET_HIGH;
		}
		else
		{
			DATA_DISPLAY_SET_LOW;
		}
		CLOCK_DISPLAY_SET_HIGH;
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		CLOCK_DISPLAY_SET_LOW;

		asm("NOP");
		data = data >> 1;
	}
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	DATA_DISPLAY_SET_LOW;
	ENABLE_DISPLAY_SET_HIGH;
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	ENABLE_DISPLAY_SET_LOW;
}

void Clear_All_Lines(void)
{
	unsigned int i;
	DATA_3DISPLAY_SET_LOW;
	CLOCK_DISPLAY_SET_LOW;
	
	for(i = 0; i<=15; i++)
	{
		CLOCK_DISPLAY_SET_HIGH;
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		CLOCK_DISPLAY_SET_LOW;
	}
}

/***********************************************************************
* Function to send a command to LCD
*
***********************************************************************/
void Send_Command_Page2(unsigned char Value)
{
	//   RW_LO();
	//   CS1_LO();
		//   CS2_HI();
	//   DI_LO();

	unsigned int Temp = 0b0100000000000000;  // DI,CS1,RW = lo, CS2 = hi,

	if(Value & 0x80) // D7
	{
		Temp = Temp | 0x1000;
	}
	if(Value & 0x40) // D6
	{
		Temp = Temp | 0x0800;
	}
	if(Value & 0x20) // D5
	{
		Temp = Temp | 0x0400;
	}
	if(Value & 0x10) // D4
	{
		Temp = Temp | 0x0200;
	}
	if(Value & 0x08) // D3
	{
		Temp = Temp | 0x0100;
	}
	if(Value & 0x04) // D2
	{
		Temp = Temp | 0x0040;
	}
	if(Value & 0x02) // D1
	{
		Temp = Temp | 0x0020;
	}
	if(Value & 0x01) // D0
	{
		Temp = Temp | 0x0010;
	}

	send_nibble(Temp);

}
/***********************************************************************
* Function to send a command to LCD
*
***********************************************************************/
void Send_Data_Page2(unsigned char Value)
{
	//   RW_LO();
	//   CS1_LO();
	//   CS2_HI();
	//   DI_HI();
	unsigned int Temp = 0b0101111101110100;  // CS1,RW = lo, DI,CS2 = hi,

	if(Value & 0x80) // D7
	{
		Temp = Temp | 0x1000;
	}
	if(Value & 0x40) // D6
	{
		Temp = Temp | 0x0800;
	}
	if(Value & 0x20) // D5
	{
		Temp = Temp | 0x0400;
	}
	if(Value & 0x10) // D4
	{
		Temp = Temp | 0x0200;
	}
	if(Value & 0x08) // D3
	{
		Temp = Temp | 0x0100;
	}
	if(Value & 0x04) // D2
	{
		Temp = Temp | 0x0040;
	}
	if(Value & 0x02) // D1
	{
		Temp = Temp | 0x0020;
	}
	if(Value & 0x01) // D0
	{
		Temp = Temp | 0x0010;
	}

	send_nibble(Temp);
	
}
/***********************************************************************
* Function to send a command to LCD
*
***********************************************************************/
void Send_Command_Page1(unsigned char Value)
{
	//   RW_LO();
	//   CS1_HI();
	//   CS2_LO();
	//   DI_LO();

	unsigned int Temp = 0b0010000000000000;

	if(Value & 0x80) // D7
	{
		Temp = Temp | 0x1000;
	}
	if(Value & 0x40) // D6
	{
		Temp = Temp | 0x0800;
	}
	if(Value & 0x20) // D5
	{
		Temp = Temp | 0x0400;
	}
	if(Value & 0x10) // D4
	{
		Temp = Temp | 0x0200;
	}
	if(Value & 0x08) // D3
	{
		Temp = Temp | 0x0100;
	}
	if(Value & 0x04) // D2
	{
		Temp = Temp | 0x0040;
	}
	if(Value & 0x02) // D1
	{
		Temp = Temp | 0x0020;
	}
	if(Value & 0x01) // D0
	{
		Temp = Temp | 0x0010;
	}

	send_nibble(Temp);

}
/***********************************************************************
* Function to send a command to LCD
*
***********************************************************************/
void Send_Data_Page1(unsigned char Value)
{
	//   RW_LO();
	//   CS1_HI();
	//   CS2_LO();
	//   DI_HI();
	unsigned int Temp = 0b0011111101110100;  // CS1,RW = lo, DI,CS2 = hi,

	if(Value & 0x80) // D7
	{
		Temp = Temp | 0x1000;
	}
	if(Value & 0x40) // D6
	{
		Temp = Temp | 0x0800;
	}
	if(Value & 0x20) // D5
	{
		Temp = Temp | 0x0400;
	}
	if(Value & 0x10) // D4
	{
		Temp = Temp | 0x0200;
	}
	if(Value & 0x08) // D3
	{
		Temp = Temp | 0x0100;
	}
	if(Value & 0x04) // D2
	{
		Temp = Temp | 0x0040;
	}
	if(Value & 0x02) // D1
	{
		Temp = Temp | 0x0020;
	}
	if(Value & 0x01) // D0
	{
		Temp = Temp | 0x0010;
	}

	send_nibble(Temp);

}
/***********************************************************************
* Clear Screen
*
***********************************************************************/
void Clear_Page2(void)
{
	unsigned char row,col;
	unsigned char dummy_xaddr;
	dummy_xaddr = set_xaddr;

	Send_Command_Page2(set_xaddr);
	Send_Command_Page2(set_yaddr);

	for(row=0;row<=7;row++)
	{
		for(col=0;col<=7;col++)
		{
			Send_Data_Page2(0x00);
		}
		set_xaddr = set_xaddr - 1;

		Send_Command_Page2(set_xaddr);
		Send_Command_Page2(set_yaddr);
	}
	set_xaddr = dummy_xaddr;
}
/***********************************************************************
* Clear Screen
*
***********************************************************************/
void Clear_Page1(void)
{
	unsigned char row,col;
	unsigned char dummy_xaddr;
	dummy_xaddr = set_xaddr;

	Send_Command_Page1(set_xaddr);
	Send_Command_Page1(set_yaddr);

	for(row=0;row<=7;row++)
	{
		for(col=0;col<=7;col++)
		{
			Send_Data_Page1(0x00);
		}
		set_xaddr = set_xaddr - 1;

		Send_Command_Page1(set_xaddr);
		Send_Command_Page1(set_yaddr);
	}
	set_xaddr = dummy_xaddr;
}

void Clear_Display(void)
{
	unsigned char i;
	set_xaddr = 0xbf;
	set_yaddr = 0x40;
	for(i=0;i<=7;i++)
	{
		Clear_Page1();
		Clear_Page2();
		set_xaddr = 0xbf;
		set_yaddr = set_yaddr + 8;
	}

}

void disp_page1_small(void)
{
 unsigned char line=1;
 unsigned char dummy_xaddr,dummy_yaddr;
 unsigned char Temp = 0;

    dummy_xaddr = set_xaddr;
	dummy_yaddr = set_yaddr;

     Send_Command_Page1(set_xaddr);
	  Send_Command_Page1(set_yaddr);

	 while(line<=line_limit)
	  {

        Temp = *data_ptr++;
        Send_Data_Page1(Temp);		// Debraj's Comment -- Complement the bits if display need to be inverted in color

    	  set_yaddr = set_yaddr + 1; // y addr incrementing
         Send_Command_Page1(set_yaddr);
		  line++;
	}// end of while
}
/********************************************************************
 *
 *
 ********************************************************************/
void disp_page2_small(void)
{
 unsigned char line=1;
 unsigned char dummy_xaddr,dummy_yaddr;
 unsigned char Temp = 0;

    dummy_xaddr = set_xaddr;
	dummy_yaddr = set_yaddr;

     Send_Command_Page2(set_xaddr);
	  Send_Command_Page2(set_yaddr);

	 while(line<=line_limit)
	  {

        Temp = *data_ptr++;
        Send_Data_Page2(Temp);		// Debraj's Comment -- Complement the bits if display need to be inverted in color

    	  set_yaddr = set_yaddr + 1; // y addr incrementing
         Send_Command_Page2(set_yaddr);
		  line++;
	}// end of while
}


void graphic_init(){
	unsigned int count2, count3;
	ENABLE_DISPLAY_SET_OUTPUT;
	DATA_DISPLAY_SET_OUTPUT;
	CLOCK_DISPLAY_SET_OUTPUT;
	
    Clear_All_Lines();
	
	for(count2 = 0; count2 <= 10; count2++)
		for(count3 = 0; count3 <= 60000; count3++);              // Wait for > 15mSec after RESET
	//---------------------------------------------------------------
	Send_Command_Page1(0x3F);

	Send_Command_Page1(0xC0);     // For startup line - 0

	Send_Command_Page2(0x3F);

	Send_Command_Page2(0xC0);     // For startup line - 0

	Clear_Display();	
}
