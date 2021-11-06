#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"

#include<avr/delay.h>


int main(){

	// HW init
	SEVENSEG_INIT();

	// super loop
	while(1)
	{
		SEVENSEG_COUNTER();

//		SEVENSEG_DISPLAY(12);
	}

	return 0;
}



