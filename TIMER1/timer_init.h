/*
 * timer.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Ammar
 */

#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

#include "std_types.h"

#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define TCNT1 *((volatile u8 *)0x4C)
#define TIMSK *((volatile u8 *)0x59)
#define OCR1AH *((volatile u8 *)0x4B)
#define OCR1AL *((volatile u8 *)0x4A)
#define OCR1BH *((volatile u8 *)0x49)
#define OCR1BL *((volatile u8 *)0x48)
#define ICR1 *((volatile u16 *)0x46) // ICRL + ICRH
#define TIFR *((volatile u8 *)0x58)

void timer1_ICU_init();

#endif /* TIMER_INIT_H_ */
