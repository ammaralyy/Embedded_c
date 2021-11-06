#include "std_types.h"
#include "DIO_Reg.h"
#include "utilities.h"
#include "Dio_Int.h"

#include <stdlib.h>

#include "I2C_init.h"


int main(int argc, char **argv) {

	I2C_INIT_MASTER();

	while (1) {

		I2C_Start();

		I2C_Send_ADDRESS_WRITE(0b01000000);

		I2C_WriteByte(0x20);

//		I2C_WriteByte(30);

		I2C_Stop();

	}
}

