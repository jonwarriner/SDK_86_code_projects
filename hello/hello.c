/**************************************************************************************/

/**************************************************************************************/

#include <I86.H>
#include "types.h"
#include "digits.h"
#include "Intl8279.h"

#define 	DISP_CTRL_ADDR	0x0FFEA
#define		DISP_STAT_ADDR	0x0FFEA
#define		DISP_DATA_ADDR	0x0FFE8

uint8_t display_buf[8] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

/*uint8_t message[19] = {'G', 'o', 'a', 't', ' ', 'r', 'o', 'd', 'e', 'o', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};*/
uint8_t message[27] = {'J', 'a', 'n', 'n', 'a', ' ', 'L', 'i', 'g', 'h', 't', 's', ' ', 'F', 'a', 'r', 't', 's', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

/*extern uint16_t ReadData();*/                     

void main()
{
/*uint16_t key;*/
/*uint8_t cnt = ' ';*/
uint8_t cnt = 0;
uint16_t i, j;

	Init_8279();
	
	/* Clear the display */
	outword(DISP_CTRL_ADDR, 0x0D3);
	for(i = 0; i < 100; i++);	
	
	while(1)
	{
		for(i = 0; i < 10000; i++);
		
		/* print the contents of the display buffer */
/*		for(i = 0; i < sizeof(display_buf); i++)*/
		for(i = 0; i < 8; i++)
		{
			outword(DISP_CTRL_ADDR, 0x080 + i);									/* output WRITE DISPLAY to control word */
			for(j = 0; j < 100; j++);
			outword(DISP_DATA_ADDR, (uint16_t)decode_7seg(display_buf[i]));		/* output the new display data */
			for(j = 0; j < 100; j++);
		}
		
		/* increment the counter but make sure it stays in the range of 0 - 6 */
		cnt++;
/*		if(cnt > 'z')*/
		if(cnt > 26)
		{
/*			cnt = ' ';*/
			cnt = 0;
		}

		/* shift the characters to the left and insert a new character from the right */
/*		for(i = sizeof(display_buf) - 1; i > 1; i--)*/
		for(i = 7; i > 0; i--)
		{
			display_buf[i] = display_buf[i-1];
		}
/*		display_buf[0] = cnt;*/
		display_buf[0] = message[cnt];
		
		/* Has a key been pressed? */
/*		if((inword(DISP_STAT_ADDR) & 0x000F) != 0)
		{*/
			/* increment the counter but make sure it stays in the range of 0 - 6 */
/*			cnt++;
			if(cnt >= 0x07)
			{
				cnt = 1;
			}
			
			key = ReadData();*/						/* read the key data */
			/*for(i = 0; i < 100; i++);*/
			/*outword(DISP_CTRL_ADDR, 0x087);*/			/* output WRITE DISPLAY to control word */
			/*for(i = 0; i < 100; i++);*/
			/*outword(DISP_DATA_ADDR, nums[cnt-1]);*/		/* outputthe new display data */
/*			for(i = 0; i < 100; i++);

		}*/
		
		
	}
}
