/*
 * SPI_init.h
 *
 *  Created on: Oct 22, 2021
 *      Author: Ammar
 */

#ifndef I2C_INIT_H_
#define I2C_INIT_H_

#include "std_types.h"
#include "utilities.h"
#include "DIO_Reg.h"
#include "Dio_Int.h"

#define TWCR *((volatile u8 *)0x56)
#define TWSR *((volatile u8 *)0x21)
#define TWDR *((volatile u8 *)0x23)
#define TWAR *((volatile u8 *)0x22)
#define TWBR *((volatile u8 *)0x20)

void I2C_INIT_MASTER(void);

void I2C_INIT_SLAVE(void);

void I2C_Start(void);

void I2C_Stop(void);

void I2C_Send_ADDRESS_READ(u8 address);

void I2C_Send_ADDRESS_WRITE(u8 address);

void I2C_WriteByte(u8 data);

u8 I2C_ReadByte(void);

#endif /* I2C_INIT_H_ */
