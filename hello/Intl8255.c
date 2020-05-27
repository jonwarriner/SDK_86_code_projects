#include "Intl8255.h"


/* Initialize Intel 8255 Programmable Peripheral Interface */
void Init_8255A()
{
	/* Initial Port 1A as outputs, 1B as inputs and 1C as inputs */
	INTL8255A_P1_CNTL_WRITE(INTL8255A_MODE0_7);
	INTL8255A_P1A_WRITE(0);		/* Make sure all of the bits of port 1A start out low */
	
	/* Initial Port 2A as inputs, 2B as inputs and 2C as inputs */
	/*INTL8255A_P2_CNTL_WRITE(INTL8255A_MODE0_15);*/
	INTL8255A_P2_CNTL_WRITE(INTL8255A_MODE0_7);
	
}
