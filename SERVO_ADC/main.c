#include <avr/delay.h>
#include "utilities.h"
#include "timer_init.h"

int main(int argc, char **argv)
{
	u32 analog_value, digital_value;

	ADC_INIT();
	timer_init();

	while(1){

		digital_value = ADC_READ();

		analog_value = (digital_value * 5 * 1000) / 1023;

//		 if(analog_value >= 0 && analog_value < 1500){
//			timer_PWM_setting(15);
//		}else if(analog_value >= 1500 && analog_value < 2400){
//			timer_PWM_setting(24);
//		} else if(analog_value >= 2400){
//			timer_PWM_setting(32);
//
//		}

		timer_PWM_setting(analog_value / 100);
	}
}

