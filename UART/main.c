#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"

#include <stdlib.h>

int main(int argc, char **argv)
{
	UART_Init();

	LED0_Init();

	u8 charr = 0;

	while(1){

		charr = UART_RECIVE();

		if(charr == 1){
			LED0_ON();
		}

		if(charr == 0){
			LED0_OFF();
		}

	}
}

