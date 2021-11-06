/*
 * timer.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Ammar
 */

#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

#include "std_types.h"

#define SREG *((volatile u8 *)0x5F) // general interupt
#define TCCR0 *((volatile u8 *)0x53) // timer register
#define TCNT0 *((volatile u8 *)0x52) // counter
#define TIMSK *((volatile u8 *)0x59) // timer pie
#define OCR0 *((volatile u8 *)0x5C)

void timer_int(void);

void timer_PWM_setting(u8 duty);

#endif /* TIMER_INIT_H_ */
