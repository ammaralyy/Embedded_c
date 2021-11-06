/*
 * timer.h
 *
 *  Created on: Oct 8, 2021
 *      Author: Ammar
 */

#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

#include "std_types.h"

#define MCUCSR *((volatile u8 *)0x54)
#define WDTCR *((volatile u8 *)0x41)

void timer1_ICU_init();

#endif /* TIMER_INIT_H_ */
