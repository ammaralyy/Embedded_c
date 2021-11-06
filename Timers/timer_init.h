/*
 * timer.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Ammar
 */

#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

#define SREG *((volatile u8 *)0x5F) // general interupt
#define TCCR0 *((volatile u8 *)0x53) // timer register
#define TCNT0 *((volatile u8 *)0x52) // counter
#define TIMSK *((volatile u8 *)0x59) // timer pie


void timer_int();


#endif /* TIMER_INIT_H_ */
