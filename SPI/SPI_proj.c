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

#include "SPI_init.h"

void SPI_INIT_MASTER(void) {

	Dio_SetPinDirection(GroupB, PIN5, OUTPUT); // MOSI output
	Dio_SetPinDirection(GroupB, PIN7, OUTPUT); // CLOCK output
	Dio_SetPinDirection(GroupB, PIN4, OUTPUT); // ss/cs output

	Dio_SetPinDirection(GroupB, PIN6, INPUT); // MISO input

	set_bit(SPCR, 4); // master mode

	clear_bit(SPCR, 3); // Clock speed to raising

	set_bit(SPCR, 6); // enable SPI

}

void SPI_INIT_SLAVE(void) {

	Dio_SetPinDirection(GroupB, PIN5, INPUT); // MOSI input
	Dio_SetPinDirection(GroupB, PIN7, INPUT); // CLOCK input
	Dio_SetPinDirection(GroupB, PIN4, INPUT); // ss/cs input

	Dio_SetPinDirection(GroupB, PIN6, OUTPUT); // MISO output

	clear_bit(SPCR, 4); // slave mode

	set_bit(SPCR, 6); // enable SPI

}

void SPI_SEND_DATA(u8 data) {

	SPDR = data;

	while (get_bit(SPSR, 7) == 0)
		; // data send

}

u8 SPI_RECIVE_DATA(void) {
	while (get_bit(SPSR, 7) == 0)
		; // data recived

	return SPDR;
}
