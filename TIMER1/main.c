#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"

#include <stdlib.h>

#include "timer_init.h"

int main(int argc, char **argv)
{
//	timer1_ICU_init();

	u16 TON = 0, TOF = 0, period = 0, freq = 0;

	u8 word[8] = {0};

	LCD_INIT();

	LCD_WRITE_COMMEND(0x80); //write first row address 0

	LCD_WRITE_WORD("frequncy:");

	while(1){

//		set_bit(TCCR1B, 6); // icu capture rising
		set_bit(TIFR, 5); // clear flag
		TCNT1 =0;
		TCCR1B = 0x45;

		while(get_bit(TIFR, 5) == 0);

		set_bit(TIFR, 5); // clear flag

		TCNT1 = 0;

//		clear_bit(TCCR1B, 6); // falling
		TCCR1B = 0x05;

		while(get_bit(TIFR, 5) == 0);

		TON = ICR1;

		set_bit(TIFR, 5); // clear flag

		TCNT1 = 0;

//		set_bit(TCCR1B, 6); // icu capture rising
		TCCR1B = 0x45;

		while(get_bit(TIFR, 5) == 0);

		TOF = ICR1;

		set_bit(TIFR, 5); // clear flag

		TCNT1 = 0;

		freq = 16000/(TON + TOF);

//		itoa(TON, word, 10);
		itoa(freq, word, 10);



		LCD_WRITE_COMMEND(0xc0); //write second row address 1

		LCD_WRITE_WORD(word);

	}
}

