/*
 * UART_init.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Ammar
 */

#ifndef UART_INIT_H_
#define UART_INIT_H_

#include "std_types.h"

#define UDR *((volatile u8 *)0x2C)
#define UCSRA *((volatile u8 *)0x2B)
#define UCSRB *((volatile u8 *)0x2A)
#define UCSRC *((volatile u8 *)0x40)
#define UBBRH *((volatile u8 *)0x40)
#define UBBRL *((volatile u8 *)0x29)

void UART_Init();

void UART_SEND(u8 data);

u8 UART_RECIVE();

#endif /* UART_INIT_H_ */
