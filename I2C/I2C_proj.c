/*
 * SPI_proj.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Ammar
 */
#include "std_types.h"
#include "utilities.h"
#include "DIO_Reg.h"
#include "Dio_Int.h"

#include "I2C_init.h"

void I2C_INIT_MASTER(void) {


	//TWSR = 0X00;
	TWBR = 0x0C; // clock
	set_bit(TWCR, 2); // enable I2C

}

void I2C_INIT_SLAVE(void) {
	TWAR = 0x06;
	set_bit(TWCR, 2); // enable I2C

}

void I2C_Start(void) {
	set_bit(TWCR, 7);
	set_bit(TWCR, 5); // start condition
	set_bit(TWCR, 2); // enable I2C

	while (get_bit(TWCR, 7) == 0); // flag done
	while ((TWDR & 0xF8) != 0x08); // start stutus

	//set_bit(TWCR, 7);
}

void I2C_Stop(void) {
	set_bit(TWCR, 4); // stop condition

	//while (get_bit(TWCR, 7) == 0); // flag done

//	while((TWDR & 0xF8) != 0x08); // stop stutus

}

void I2C_Send_ADDRESS_READ(u8 address) {
	TWAR = address;

	set_bit(TWAR, 0);

	set_bit(TWCR, 7);
	set_bit(TWCR, 2);

	while (get_bit(TWCR, 7) == 0); // flag done

	while ((TWDR & 0xF8) != 0x40); // read stutus

}

void I2C_Send_ADDRESS_WRITE(u8 address) {
	TWAR = address;

	clear_bit(TWAR, 0);

	set_bit(TWCR, 7);
	set_bit(TWCR, 2);

	while (get_bit(TWCR, 7) == 0); // flag done

	while ((TWDR & 0xF8) != 0x18); // write stutus

}

void I2C_WriteByte(u8 data){
	TWDR = data;

	while (get_bit(TWCR, 7) == 0); // flag done

	while ((TWDR & 0xF8) != 0x28); // write stutus
	set_bit(TWCR, 7);
}

u8 I2C_ReadByte(void){

	while (get_bit(TWCR, 7) == 0); // flag done

	while ((TWDR & 0xF8) != 0x58); // write stutus

	return TWDR;
}
