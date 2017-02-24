#include "LCD/LCD_Config.h"
#include "Keypad/Keypad_Comfig.h"

int main(void){	
	LCD_Init(&PIND, &PIND, 0, 1, 2, 3, 4, 5, 6);
	Keypad_Init();
	
	u8 Keypad_Read = 0;
	u8 Element = '0';
	
    while (1){
		Keypad_Read = Keypad_Scan();
		if(Keypad_Read != 0)
			LCD_Char(Keypad_Read);
    }
}
