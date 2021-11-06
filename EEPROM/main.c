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

#include "EEPROM_init.h"
#include "LED_INIT.h"


#define F_CPU 16000000UL

u8 data = 0;


void main(void)
{
	data = 0;

	LED1_Init();

	EEPROM_Init();
	_delay_ms(100);

	EEPROM_WRITE_DATA(700, 0x0F);
	_delay_ms(100);

	data = EEPROM_READ_DATA(700);
	_delay_ms(100);

	if(data == 0x0F)
		LED1_ON();

	while(1)
	{

	}
}
