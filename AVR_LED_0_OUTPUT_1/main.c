#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"

//#include<avr/delay.h>

int main(){

	// HW init
	set_bit(DDRC, 2); // output
	set_bit(DDRC, 7);
	set_bit(DDRD, 3);

	clear_bit(DDRD, 2);
	clear_bit(DDRD, 6); // input
//	set_bit(PORTD, 2); // internal pull-up resistor
	 u8 counter = 0;

	// super loop
	while(1)
	{
		if(((get_bit(PIND, 2)) == 1) && counter < 7)
		{
			while((get_bit(PIND, 2)) == 1);
			counter++;

			if(get_bit(counter, 0))
				set_bit(PORTC, 2);
			else
				clear_bit(PORTC,2);

			if(get_bit(counter, 1))
				set_bit(PORTC, 7);
			else
				clear_bit(PORTC,7);

			if(get_bit(counter, 2))
				set_bit(PORTD, 3);
			else
				clear_bit(PORTD,3);
		}


		if(((get_bit(PIND, 6)) == 1) && counter > 0)
		{
			while((get_bit(PIND, 6)) == 1);
			counter--;

			if(get_bit(counter, 0))
				set_bit(PORTC, 2);
			else
				clear_bit(PORTC,2);

			if(get_bit(counter, 1))
				set_bit(PORTC, 7);
			else
				clear_bit(PORTC,7);

			if(get_bit(counter, 2))
				set_bit(PORTD, 3);
			else
				clear_bit(PORTD,3);
		}

	}

	return 0;
}

