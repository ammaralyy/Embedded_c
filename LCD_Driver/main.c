#include "LCD_DRIVER.h"
#include <avr/delay.h>

int main(int argc, char **argv) {

	LCD_INIT();

	LCD_WRITE_COMMEND(0x80); //write first row address 0

	LCD_WRITE_WORD("wezza");

//	LCD_WRITE_DATA('w');
//	LCD_WRITE_DATA('e');
//	LCD_WRITE_DATA('z');
//	LCD_WRITE_DATA('z');
//	LCD_WRITE_DATA('a');



	LCD_WRITE_COMMEND(0xc0); //write second row address 1

	LCD_WRITE_WORD("loda");

//	LCD_WRITE_DATA('l');
//	LCD_WRITE_DATA('o');
//	LCD_WRITE_DATA('d');
//	LCD_WRITE_DATA('a');


	while(1){

	}

}
