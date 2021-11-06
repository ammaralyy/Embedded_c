#ifndef DIO_Reg.h
#define DIO_Reg .h

#define PORTA *((voltile u8 *)0x3B)
#define DDRA *((voltile u8 *)0x3A)
#define PINA *((voltile u8 *)0x39)

#define PORTB *((voltile u8 *)0x38)
#define DDRB *((voltile u8 *)0x37)
#define PINB *((voltile u8 *)0x36)

#define PORTC *((voltile u8 *)0x35)
#define DDRC *((voltile u8 *)0x34)
#define PINC *((voltile u8 *)0x33)

#define PORTD *((voltile u8 *)0x32)
#define DDRD *((voltile u8 *)0x31)
#define PIND *((voltile u8 *)0x30)

#endif