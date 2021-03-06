/*
 * EEPROM_init.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Ammar
 */

#ifndef EEPROM_INIT_H_
#define EEPROM_INIT_H_

#include "Std_Types.h"
#include "Utilites.h"
#include "I2C_Int.h"
#include "EEPROM_init.h"


void EEPROM_Init();
void EEPROM_WRITE_DATA(u16 address, u8 data);
u8 EEPROM_READ_DATA(u16 address);

#endif /* EEPROM_INIT_H_ */
