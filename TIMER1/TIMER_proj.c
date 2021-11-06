#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"
#include "avr/interrupt.h"

#include "timer_init.h"

void timer1_ICU_init(){
	set_bit(TCCR1B, 0);
	clear_bit(TCCR1B, 1);
	set_bit(TCCR1B, 2);
}


