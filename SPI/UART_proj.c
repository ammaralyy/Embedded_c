#include "std_types.h"
#include "utilities.h"
#include "DIO_Reg.h"
#include "Dio_Int.h"

#include "UART_init.h"

void UART_Init()
{

	set_bit(UCSRB,3); // Enable TX
	set_bit(UCSRB,4); // Enable RX

	clear_bit(UCSRB, 2);
	set_bit(UCSRC,1);
	set_bit(UCSRC,2); // 8 bit data size

	clear_bit(UCSRC, 4);
	clear_bit(UCSRC, 5); // disable party

	clear_bit(UCSRC, 6); // Asynchrouns

	clear_bit(UCSRC, 3); // 1 bit stop bit

	UBBRL = 103;
	UBBRH = 0;// boad rate = 9600
}

void UART_SEND(u8 data){
	while(get_bit(UCSRA, 5) == 0); // transmission complete

	UDR = data;
}

u8 UART_RECIVE(){
	while(get_bit(UCSRA, 7) == 0); // recive complete

	return UDR;
}

