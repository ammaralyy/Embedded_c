#ifndef ADC_INIT_H_
#define ADC_INIT_H_

#include "std_types.h"

#define ADMUX *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCH *((volatile u8 *)0x25)
#define ADCL *((volatile u8 *)0x24)

void ADC_INIT();

u16 ADC_READ();

#endif /* ADC_INIT_H_ */
