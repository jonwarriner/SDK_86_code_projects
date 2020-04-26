/**************************************************************************************/

/**************************************************************************************/

#include <I86.H>
#include "types.h"
#include "digits.h"

#define 	DISP_CTRL_ADDR	0x0FFEA
#define		DISP_STAT_ADDR	0x0FFEA
#define		DISP_DATA_ADDR	0x0FFE8

/*extern uint16_t ReadData();*/                     

/*uint16_t ReadData()
{
	outword(DISP_CTRL_ADDR, 0x040);
	return(inword(DISP_DATA_ADDR));
}*/

void main()
{
uint16_t key;
uint8_t cnt = ' ';
uint16_t i;

	/* Clear the display */
	outword(DISP_CTRL_ADDR, 0x0D3);
	for(i = 0; i < 100; i++);	
	outword(DISP_CTRL_ADDR, 0x080);			/* output WRITE DISPLAY to control word */
	for(i = 0; i < 100; i++);
	outword(DISP_DATA_ADDR, (uint16_t)decode_7seg((uint8_t)cnt));		/* output the new display data */
	
	while(1)
	{
		for(i = 0; i < 10000; i++);
		
		/* increment the counter but make sure it stays in the range of 0 - 6 */
		cnt++;
		if(cnt > 'z')
		{
			cnt = ' ';
		}
		outword(DISP_CTRL_ADDR, 0x080);			/* output WRITE DISPLAY to control word */
		for(i = 0; i < 100; i++);
		outword(DISP_DATA_ADDR, (uint16_t)decode_7seg((uint8_t)cnt));		/* output the new display data */
		
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
