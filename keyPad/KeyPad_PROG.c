#include "Std_Types.h"
#include "Utilities.h"
#include "KeyPad_INIT.h"
#include "Dio_Int.h"
#include "Dio_Reg.h"

void KeyPad_INIT(void)  {

	// coloumes outputs
	Dio_SetPinDirection(GroupB, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupB, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupB, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupB, PIN7, OUTPUT);

	// rows inputs
	Dio_SetPinDirection(GroupD, PIN0, INPUT);
	Dio_SetPinDirection(GroupD, PIN1, INPUT);
	Dio_SetPinDirection(GroupC, PIN0, INPUT);
	Dio_SetPinDirection(GroupC, PIN1, INPUT);

	// define rows as internal pull up res

	Dio_SetPinValue(GroupD, PIN0, HIGH);
	Dio_SetPinValue(GroupD, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1, HIGH);

}

u8 KeyPad_GetKey() {

	u8 pressed_key = 0xff;

	// set column 0
	Dio_SetPinValue(GroupB, PIN4, LOW);
	Dio_SetPinValue(GroupB, PIN5, HIGH);
	Dio_SetPinValue(GroupB, PIN6, HIGH);
	Dio_SetPinValue(GroupB, PIN7, HIGH);

	if (Dio_GetPinValue(GroupD, PIN0) == 0) {
		pressed_key = 1;
	}
	if (Dio_GetPinValue(GroupD, PIN1) == 0) {
		pressed_key = 4;
	}
	if (Dio_GetPinValue(GroupC, PIN0) == 0) {
		pressed_key = 7;
	}
	if (Dio_GetPinValue(GroupC, PIN1) == 0) {
		pressed_key = '*';
	}

	// set column 1
	Dio_SetPinValue(GroupB, PIN4, HIGH);
	Dio_SetPinValue(GroupB, PIN5, LOW);
	Dio_SetPinValue(GroupB, PIN6, HIGH);
	Dio_SetPinValue(GroupB, PIN7, HIGH);

	if (Dio_GetPinValue(GroupD, PIN0) == 0) {
		pressed_key = 2;
	}
	if (Dio_GetPinValue(GroupD, PIN1) == 0) {
		pressed_key = 5;
	}
	if (Dio_GetPinValue(GroupC, PIN0) == 0) {
		pressed_key = 8;
	}
	if (Dio_GetPinValue(GroupC, PIN1) == 0) {
		pressed_key = 0;

	}

	// set column 2
	Dio_SetPinValue(GroupB, PIN4, HIGH);
	Dio_SetPinValue(GroupB, PIN5, HIGH);
	Dio_SetPinValue(GroupB, PIN6, LOW);
	Dio_SetPinValue(GroupB, PIN7, HIGH);

	if (Dio_GetPinValue(GroupD, PIN0) == 0) {
		pressed_key = 3;
	}
	if (Dio_GetPinValue(GroupD, PIN1) == 0) {
		pressed_key = 6;
	}
	if (Dio_GetPinValue(GroupC, PIN0) == 0) {
		pressed_key = 9;
	}
	if (Dio_GetPinValue(GroupC, PIN1) == 0) {
		pressed_key = '#';

	}

	// set column 3
	Dio_SetPinValue(GroupB, PIN4, HIGH);
	Dio_SetPinValue(GroupB, PIN5, HIGH);
	Dio_SetPinValue(GroupB, PIN6, HIGH);
	Dio_SetPinValue(GroupB, PIN7, LOW);

	if (Dio_GetPinValue(GroupD, PIN0) == 0) {
		pressed_key = 'A';
	}
	if (Dio_GetPinValue(GroupD, PIN1) == 0) {
		pressed_key = 'B';
	}
	if (Dio_GetPinValue(GroupC, PIN0) == 0) {
		pressed_key = 'C';
	}
	if (Dio_GetPinValue(GroupC, PIN1) == 0) {
		pressed_key = 'D';

	}

	return pressed_key;
}

