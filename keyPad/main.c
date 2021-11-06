/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: Mohamed
 */

#include "Std_Types.h"
#include "KeyPad_INIT.h"
#include "Dio_Reg.h"

void main(void)
{
	//HW INIT

	KeyPad_INIT();
	SEVENSEG_INIT();

	u8 var;

	while(1)
	{
		var = KeyPad_GetKey();

		SEVENSEG_DISPLAY(var);
	}
}
