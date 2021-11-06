#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"
#include "avr/interrupt.h"

#include "timer_init.h"

u16 counter = 0;

void timer_init()
{
	set_bit(SREG, 7); // set GIE -> 1

	clear_bit(TCCR0, 6);
	clear_bit(TCCR0, 3); // normal mode

	set_bit(TCCR0, 0);
	set_bit(TCCR0, 1); // prescaler external raising
	set_bit(TCCR0, 2);

	TCNT0 = 254; // set initial value of TCNT0

	set_bit(TIMSK, 0); // enable pie

	clear_bit(DDRB, 0);

	LED0_Init();

}

ISR(TIMER0_OVF_vect){

	counter++;

	if(counter == 1)
	{
		counter = 0;

		toggle_bit(PORTC, PIN2);

		TCNT0 = 254;
	}
}

