#include "Keypad_Comfig.h"

/*...........................................................................
  Name:     Keypad_Init.
  Purpose:  Initialization function for Keypad.
  Entry:    no parameters
  Exit:     no parameters
*/
void Keypad_Init( void ){
	/*	Set all Row pins to output	*/
	Row0_DDR |= (1 << Row0);
	Row1_DDR |= (1 << Row1);
	Row2_DDR |= (1 << Row2);
	Row3_DDR |= (1 << Row3);
	
	/*	Set all Line pins to input	*/
	Line0_DDR &=~(1 << Line0);
	Line1_DDR &=~(1 << Line1);
	Line2_DDR &=~(1 << Line2);
	Line3_DDR &=~(1 << Line3);
	
	/*	Activate the pull-up resistor of the input to drive them high	*/
	Line0_PullUP |= (1 << Line0);
	Line1_PullUP |= (1 << Line1);
	Line2_PullUP |= (1 << Line2);
	Line3_PullUP |= (1 << Line3);
}

/*...........................................................................
  Name:     Keypad_Scan.
  Purpose:  Scan the keypad Pins and determine the output.
  Entry:    no parameters
  Exit:     (u8) The value of pressed key in ascii.
*/
u8 Keypad_Scan ( void ){
	u8 ROW		= 0;
	u8 Input	= 0;
	
	for(ROW = 0; ROW < 4; ROW++){
		/*	Set all Row pins to High	*/
		Row0_Port |= (1 << Row0);
		Row1_Port |= (1 << Row1);
		Row2_Port |= (1 << Row2);
		Row3_Port |= (1 << Row3);
		
		/*	Switch on Row pins and drive them low one by one	*/
		switch (ROW){
			case 0	: Row0_Port &=~(1 << Row0); break;
			case 1	: Row1_Port &=~(1 << Row1); break;
			case 2	: Row2_Port &=~(1 << Row2); break;
			default	: Row3_Port &=~(1 << Row3); break;
		}
		
		/*	Read the input	
		 *	input = 0b01110000   0x70
		 *	input = 0b10110000   0xB0
		 *	input = 0b11010000   0xD0
		 *	input = 0b11100000   0xE0
		 */
		Input  = (((Line0_PIN & (1 << Line0)) >> Line0) << 4);
		Input |= (((Line1_PIN & (1 << Line1)) >> Line1) << 5);
		Input |= (((Line2_PIN & (1 << Line2)) >> Line2) << 6);
		Input |= (((Line3_PIN & (1 << Line3)) >> Line3) << 7);
		
		/*	Check if there is valid input	*/
		if (Check_ALL_Lines != 1){
			/*	Wait until release	*/
			while (Check_ALL_Lines != 1); break;
		}
	}
	
	/*	Return the output based on number of Row and Input's value	*/
	switch (ROW){
		case 0 : switch(Input){
			case 0xE0: return '7';
			case 0xD0: return '8';
			case 0xB0: return '9';
			case 0x70: return '/';
		}
		case 1 : switch(Input){
			case 0xE0: return '4';
			case 0xD0: return '5';
			case 0xB0: return '6';
			case 0x70: return '*';
		}
		case 2 : switch(Input){
			case 0xE0: return '1';
			case 0xD0: return '2';
			case 0xB0: return '3';
			case 0x70: return '-';
		}
		case 3 : switch(Input){
			case 0xE0: return 'C';
			case 0xD0: return '0';
			case 0xB0: return '=';
			case 0x70: return '+';
		}
	}
	/*	If you didn't press any key it will return Zero	*/
	return 0;
}