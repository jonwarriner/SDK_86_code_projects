/**************************************************************************************/

/**************************************************************************************/

#include <I86.H>
#include "types.h"
#include "digits.h"
#include "keys.h"
#include "Intl8279.h"
#include "Intl8255.h"
#include "Intl8251.h"
#include "msDelay.h"
#include "my_stdio.h"
#include "logo.h"

/*#define 	DISP_CTRL_ADDR	0x0FFEA
#define		DISP_STAT_ADDR	0x0FFEA
#define		DISP_DATA_ADDR	0x0FFE8*/

#define SERIAL_TEST

uint8_t display_buf[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

/*uint8_t message[19] = {'G', 'o', 'a', 't', ' ', 'r', 'o', 'd', 'e', 'o', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};*/
/*uint8_t message[27] = {'J', 'a', 'n', 'n', 'a', ' ', 'L', 'i', 'g', 'h', 't', 's', ' ', 'F', 'a', 'r', 't', 's', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};*/

/*extern uint16_t ReadData();*/                     

void main()
{
/*uint16_t key;*/
/*uint8_t cnt = ' ';*/
uint8_t cnt = 0;
uint16_t i, j;
uint8_t test;

	disable();		/* make sure interrupts are disabled */

	/* Initialize the 8279 and clear the display and FIFO status */
	Init_8279();
	
	/* Initialize the 8255A (x2) */
	Init_8255A();

	/* Initialize the 8251A */
	Init_8251A();

	for(i = 0; i < 50000; i++);	/* big pause to check that the display cleared */
	
	printf("%c[2J%c[H\r\n\r\n", (char)27, (char)27);
	print_logo();
	
	while(1)
	{
#ifdef DISP_KEY_TEST		
		/*for(i = 0; i < 10000; i++);*/
		INTL8255A_P1A_WRITE(1);
		DELAY_MS(500);
		INTL8255A_P1A_WRITE(0);
/*		while((INTL8279_FIFO_STATUS & INTL8279_FIFO_STATUS_N_MASK) == 0)
		{
		}
		INTL8279_READ_FIFO(0, 0);
		test = INTL8279_DATA_READ;
		
		display_buf[0] = ascii_key(test & 0x3F);*/

		
		/* print the contents of the display buffer */
		for(i = 0; i < 8; i++)
		{
			INTL8279_WRITE_DISP_RAM(0, i);
			INTL8279_DATA_WRITE(decode_7seg(display_buf[i]));
		}
		
		/* increment the counter but make sure it stays in the range of 0 - 6 */
		cnt++;
		if(cnt > 26)
		{
			cnt = 0;
		}

		/* shift the characters to the left and insert a new character from the right */
		for(i = 7; i > 0; i--)
		{
			display_buf[i] = display_buf[i-1];
		}
		display_buf[0] = cnt;
		display_buf[0] = message[cnt];
#elif defined(SERIAL_TEST)
		if(INTL8251A_STATUS & INTL8251A_STATUS_RXRDY_MASK)
		{
			test = INTL8251A_RD_DATA;
			INTL8279_WRITE_DISP_RAM(0, 0);
			INTL8279_DATA_WRITE(decode_7seg(test));
			while((INTL8251A_STATUS & INTL8251A_STATUS_TXRDY_MASK) == 0);
			INTL8251A_WR_DATA(test);
		}
#else
#endif	
	}
}
