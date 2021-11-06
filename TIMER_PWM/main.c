#include <avr/delay.h>
#include "utilities.h"
#include "timer_init.h"

int main(int argc, char **argv)
{
	timer_init();

	while(1){
		timer_PWM_setting(128);
		_delay_ms(2000);
		timer_PWM_setting(64);
		_delay_ms(2000);
		timer_PWM_setting(196);
		_delay_ms(2000);
	}
}

