#include "LCD_DRIVER.h"
#include <avr/delay.h>

int main(int argc, char **argv) {

	LCD_INIT();

//	u8 FirstRowAddress = 0x80;
//	u8 SecondRowAddress = 0xc0;

	u8 flage = 0;
	u8 counter = 0x80;

	while(1){
		if(flage == 0){
			if(counter <= 0x8f){
//				LCD_INIT();
				LCD_CLEAER();
				LCD_WRITE_COMMEND(counter);
				LCD_WRITE_WORD("Ammar");
				counter++;
			}else{
				counter = 0xc0;
				flage = 1;
			}
		}else if(flage == 1){
			if(counter <= 0xcf){
//				LCD_INIT();
				LCD_CLEAER();
				LCD_WRITE_COMMEND(counter);
				LCD_WRITE_WORD("Ammar");
				counter++;
			}else{
				counter = 0x80;
				flage = 0;
			}
		}


		_delay_ms(500);

	}

}
