#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"
#include "avr/interrupt.h"

#include "timer_init.h"

void timer_init(void){

	set_bit(TCCR0, 0);
	clear_bit(TCCR0, 1); // prescaler (64)
	set_bit(TCCR0, 2);

	set_bit(TCCR0, 6);
	set_bit(TCCR0, 3); // PWM fast

	clear_bit(TCCR0,4);
	set_bit(TCCR0,5); // inverted

	set_bit(DDRB, 3); // output pin
}

void timer_PWM_setting(u8 duty)
{
	OCR0 = duty;
}

