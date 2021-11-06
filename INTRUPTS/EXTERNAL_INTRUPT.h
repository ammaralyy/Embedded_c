/*
 * INTRUPT.h
 *
 *  Created on: Oct 1, 2021
 *      Author: Ammar
 */

#ifndef EXTERNAL_INTRUPT_H_
#define EXTERNAL_INTRUPT_H_

#define MCUCR *((volatile u8 *)0x55) // raising or falling
#define SREG *((volatile u8 *)0x5F) // general interupt
#define GICR *((volatile u8 *)0x5B) // intrupt register

void EXTERNAL_INTRUPT_INIT();

ISR(INT0_vect);

#endif /* EXTERNAL_INTRUPT_H_ */
