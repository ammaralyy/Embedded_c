#include "std_types.h"
#include "utilities.h"

#include "LCD_DRIVER.h"
#include "DIO_Reg.h"

#include<avr/delay.h>

void LCD_INIT()
{
	Dio_SetPinDirection(GroupB, PIN1, OUTPUT); //RS
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT); //RW
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT); // EN

	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);

	_delay_ms(40);

	// function set
	LCD_WRITE_COMMEND(0x02); // high
	LCD_WRITE_COMMEND(0x2B); // low

	_delay_us(40);

	//display on/off
	LCD_WRITE_COMMEND(0x00);
	LCD_WRITE_COMMEND(0x0E);

	_delay_us(40);

	// clear
	LCD_WRITE_COMMEND(0x00);
	LCD_WRITE_COMMEND(0x01);

	_delay_ms(2);

	// mode
	LCD_WRITE_COMMEND(0x00);
	LCD_WRITE_COMMEND(0x04);

}

void LCD_WRITE_COMMEND(u8 command)
{
	Dio_SetPinValue(GroupB, PIN2, LOW); // RW write
	Dio_SetPinValue(GroupB, PIN1, LOW); // RS LOW => send command

	PORTA = (PORTA & 0x0f) | (command & 0xf0);
	Dio_SetPinValue(GroupB, PIN3, HIGH); // ENABLE HIGH

	_delay_ms(2);

	Dio_SetPinValue(GroupB, PIN3, LOW); // ENABLE LOW

	PORTA = (PORTA & 0x0f) | (command << 4);

	Dio_SetPinValue(GroupB, PIN3, HIGH); // ENABLE HIGH

	_delay_ms(2);

	Dio_SetPinValue(GroupB, PIN3, LOW); // ENABLE LOW
}

void LCD_WRITE_DATA(u8 data)
{
	Dio_SetPinValue(GroupB, PIN2, LOW); // RW write
		Dio_SetPinValue(GroupB, PIN1, HIGH); // RS LOW => send command

		PORTA = (PORTA & 0x0f) | (data & 0xf0);
		Dio_SetPinValue(GroupB, PIN3, HIGH); // ENABLE HIGH

		_delay_ms(2);

		Dio_SetPinValue(GroupB, PIN3, LOW); // ENABLE LOW

		PORTA = (PORTA & 0x0f) | (data << 4);
		Dio_SetPinValue(GroupB, PIN3, HIGH); // ENABLE HIGH

		_delay_ms(2);

		Dio_SetPinValue(GroupB, PIN3, LOW); // ENABLE LOW
}

void LCD_WRITE_WORD(u8 * word){

	u8 counter = 0;

	while(word[counter] != 0){
		LCD_WRITE_DATA(word[counter]);
		counter++;
	}

}

void LCD_NUM_Count(){

}
