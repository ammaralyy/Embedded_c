#include "std_types.h"
#include "utilities.h"
#include "DIO_Reg.h"

#include "ADC_init.h"

#include<avr/delay.h>

void ADC_INIT()
{
	set_bit(ADMUX, 6); //
	clear_bit(ADMUX, 7); // external ... set this to 1 to external volte 5

	clear_bit(ADMUX, 5); // right adjust if 1 left

	set_bit(ADCSRA, 0);
	set_bit(ADCSRA, 1); // prescaler 8
	clear_bit(ADCSRA, 2);

	set_bit(ADMUX, 0);
	clear_bit(ADMUX, 1);
	clear_bit(ADMUX, 2); // chanel 1
	clear_bit(ADMUX, 3);
	clear_bit(ADMUX, 4);

	set_bit(ADCSRA, 7); // enable adc

}

u16 ADC_READ()
{
	u16 ADC_VALUE = 0, ADC_LOW;

	set_bit(ADCSRA, 6); //start conversion

	while((get_bit(ADCSRA, 4)) == 0); // conversion loop

	set_bit(ADCSRA, 4); // clear flag note : set 1 to be cleared (hw specific)

	ADC_LOW = (u16)ADCL;
	ADC_VALUE = ADCH << 8;
	ADC_VALUE = ADC_VALUE | ADC_LOW ;

	return ADC_VALUE;
}

