/*
 * 7Seg_PROG.c
 *
 *  Created on: Sep 19, 2021
 *      Author: ELKHOLY
 */
#include "Std_Types.h"
#include "Dio_REG.h"
#include "Dio_Int.h"
#include "Utilities.h"
#include "7Seg_INIT.h"
#include <avr/delay.h>

void SEVENSEG_INIT() {

	// transistor enable

	Dio_SetPinDirection(GroupB, PIN1, OUTPUT); // SEG1
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT); // SEG2

	// decoder input
	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);

	// Button
	Dio_SetPinDirection(GroupD, PIN2, INPUT);
	Dio_SetPinDirection(GroupD, PIN6, INPUT);
}

void SEVENSEG_DISPLAY(u8 MAXIMUM_VALUE) {

	if (MAXIMUM_VALUE < 100)
	{
		u8 i, D1, D2;

		for (i = 0; i < 50; i++) {

			//enable digit 1
			Dio_SetPinValue(GroupB, PIN2, HIGH);
			Dio_SetPinValue(GroupB, PIN1, LOW);
			D1 = (MAXIMUM_VALUE / 10) << 4;
			PORTA = D1;

			_delay_ms(10);

			// enable digit 2
			Dio_SetPinValue(GroupB, PIN1, HIGH);
			Dio_SetPinValue(GroupB, PIN2, LOW);
			D2 = (MAXIMUM_VALUE % 10) << 4;
			PORTA = D2;
			_delay_ms(10);
		}

	}
}

void SEVENSEG_COUNTER()
{

	static counter = 0;

	if(((get_bit(PIND, 2)) == 1) && counter < 100)
	{
		while((get_bit(PIND, 2)) == 1);
		counter++;
	}

//	SEVENSEG_DISPLAY(counter);

	if(((get_bit(PIND, 6)) == 1) && counter > 0)
	{
		while((get_bit(PIND, 6)) == 1);
		counter--;
	}

	SEVENSEG_DISPLAY(counter);

}
