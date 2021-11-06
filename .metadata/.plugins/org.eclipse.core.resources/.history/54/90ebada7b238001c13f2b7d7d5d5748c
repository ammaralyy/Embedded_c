/*
 * main.c
 *
 *  Created on: Dec 11, 2020
 *      Author: Mohamed
 */
#include "Std_Types.h"
#include "Utilites.h"
#include "Dio_Reg.h"
#include "I2C_Int.h"
#include "util/delay.h"
#define F_CPU 16000000UL

void main(void)
{
	I2c_Init_Master();

	while(1)
	{
		I2c_Start();
		I2c_Send_slave_address_with_write_req( 0b01000000 /*| ((address & 0x0700)>>8) */);
		I2c_Write_byte(0x33);
		I2c_Write_byte(0x22);
		I2c_Stop();
		_delay_ms(1000);
	}
}
