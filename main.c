#include "Keypad/Keypad_Comfig.h"

int main( void ){
	Keypad_Init();
	DDRA = 0xFF;
	u8 Keypad_Read = 0;
	while (1){
		Keypad_Read = Keypad_Scan();
		if(Keypad_Read != 0)
			PORTA = Keypad_Read;
	}
}
