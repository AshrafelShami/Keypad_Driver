
#ifndef KEYPAD_COMFIG_H_
#define KEYPAD_COMFIG_H_

#include "DataTypes.h"
#include "FunctionPrototypes.h"
#include <avr/io.h>

#define Row0			0
#define Row0_DDR		DDRC
#define Row0_Port		PORTC

#define Row1			1
#define Row1_DDR		DDRC
#define Row1_Port		PORTC

#define Row2			2
#define Row2_DDR		DDRC
#define Row2_Port		PORTC

#define Row3			3
#define Row3_DDR		DDRC
#define Row3_Port		PORTC

#define Line0			4
#define Line0_DDR		DDRC
#define Line0_PIN		PINC
#define Line0_PullUP	PORTC

#define Line1			5
#define Line1_DDR		DDRC
#define Line1_PIN		PINC
#define Line1_PullUP	PORTC

#define Line2			6
#define Line2_DDR		DDRC
#define Line2_PIN		PINC
#define Line2_PullUP	PORTC

#define Line3			7
#define Line3_DDR		DDRC
#define Line3_PIN		PINC
#define Line3_PullUP	PORTC

#define Check_ALL_Lines		 (((Line0_PIN & (1 << Line0)) >> Line0)\
							 &((Line1_PIN & (1 << Line1)) >> Line1)\
							 &((Line2_PIN & (1 << Line2)) >> Line2)\
							 &((Line3_PIN & (1 << Line3)) >> Line3))
							 
#endif /* KEYPAD_COMFIG_H_ */