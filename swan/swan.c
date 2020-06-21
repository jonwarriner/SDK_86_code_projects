/**************************************************************************************/

/**************************************************************************************/

#include <I86.H>
#include "types.h"
#include "Intl8255.h"
#include "Intl8251.h"
#include "msDelay.h"
#include "my_stdio.h"
#include "logo.h"

void main()
{
uint8_t cnt = 0;
uint16_t i, j;
uint8_t test;

	disable();		/* make sure interrupts are disabled */

	/* Initialize the 8255A (x2) */
	Init_8255A();

	/* Initialize the 8251A */
	Init_8251A();

	for(i = 0; i < 50000; i++);	/* big pause to check that the display cleared */
	
	printf("%c[2J%c[H\r\n\r\n", (char)27, (char)27);
	print_logo();
	
	while(1)
	{
		INTL8255A_P1A_WRITE(1);
		DELAY_MS(500);
		INTL8255A_P1A_WRITE(0);
		if(INTL8251A_STATUS & INTL8251A_STATUS_RXRDY_MASK)
		{
			test = INTL8251A_RD_DATA;
			while((INTL8251A_STATUS & INTL8251A_STATUS_TXRDY_MASK) == 0);
			INTL8251A_WR_DATA(test);
		}
	}
}
