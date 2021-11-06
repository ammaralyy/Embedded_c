#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"
#include "LED_INIT.h"
#include "avr/delay.h"

#include <stdlib.h>

#include "timer_init.h"

int main(int argc, char **argv)
{
	set_bit(WDTCR, 3);
	LED0_Init();

	while(1)
	{
		set_bit(WDTCR, 0);
		set_bit(WDTCR, 1);
		set_bit(WDTCR, 2);

		LED0_ON();

		_delay_ms(500);

		LED0_OFF();

		while(1){
		}
	}
}

