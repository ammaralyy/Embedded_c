/*
 * EXTERNAL_INTRUPT_PROG.c
 *
 *  Created on: Oct 1, 2021
 *      Author: Ammar
 */
#include <avr/delay.h>

#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"
#include "avr/interrupt.h"


#include "EXTERNAL_INTRUPT.h"

void EXTERNAL_INTRUPT_INIT(){

	set_bit(SREG, 7); // set GIE -> 1

	set_bit(GICR, 6); // set PIE 0 -> 1

	set_bit(MCUCR, 0);
	set_bit(MCUCR, 1); // raising

	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);

}

ISR(INT0_vect)
{

	toggle_bit(PORTC, 2);

//	_delay_ms(500);
}

