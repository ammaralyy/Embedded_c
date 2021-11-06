#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"

#include <stdlib.h>

int main(int argc, char **argv) {

	SPI_INIT_SLAVE();

	LED1_Init();

	u8 charr = 0;

	while (1) {

		charr = SPI_RECIVE_DATA();

		if (charr == 1) {
			LED1_ON();
		}

		if (charr == 0) {
			LED1_OFF();
		}

	}
}

