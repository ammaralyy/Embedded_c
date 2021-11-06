#include <avr/delay.h>
#include "utilities.h"
#include "ADC_init.h"
#include "LED_INIT.h"

int main(int argc, char **argv)
{
	u32 analog_value, digital_value;

	void LED0_Init();
	void LED1_Init();
	void LED2_Init();

	ADC_INIT();

	while(1){

		digital_value = ADC_READ();

		analog_value = (digital_value * 5 * 1000) / 1023;

		if(analog_value >= 0 && analog_value < 1500){
			LED0_OFF();
			LED1_OFF();
			LED2_OFF();
		}else if(analog_value >= 1500 && analog_value < 2500){
			LED0_ON();
			LED1_OFF();
			LED2_OFF();
		}else if(analog_value >= 2500 && analog_value < 3000){
			LED0_ON();
			LED1_ON();
			LED2_OFF();
		} else if(analog_value >= 3000){
			LED0_ON();
			LED1_ON();
			LED2_ON();
		}

	}
}

