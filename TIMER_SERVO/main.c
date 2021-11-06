#include <avr/delay.h>
#include "utilities.h"
#include "timer_init.h"

int main(int argc, char **argv)
{
	timer_init();

	while(1){
		timer_PWM_setting(15);
		_delay_ms(2000);
		timer_PWM_setting(24);
		_delay_ms(2000);
		timer_PWM_setting(32);
		_delay_ms(2000);
	}
}

