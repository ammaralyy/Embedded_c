#include "Dio_Int.h"

#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

void LCD_INIT();

void LCD_WRITE_COMMEND(u8 command);

void LCD_WRITE_DATA(u8 data);

void LCD_WRITE_WORD(u8 * word);

#endif /* LCD_DRIVER_H_ */
