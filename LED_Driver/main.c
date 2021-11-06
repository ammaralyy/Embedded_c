#include "std_types.h"
#include "utilities.h"

#include "LED_INIT.h"


void main (void)
{
	LED0_Init();

	while(1)
	{
		LED0_ON();
	}
}


