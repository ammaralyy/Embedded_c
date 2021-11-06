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

	Dio_SetPinDirection(GroupB, PIN1, OUTPUT);
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT);

	// decoder input

	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);

}
void SEVENSEG_DISPLAY(u8 MAXIMUM_VALUE) {

	if (MAXIMUM_VALUE < 100) {
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
