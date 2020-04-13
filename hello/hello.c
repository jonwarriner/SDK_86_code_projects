/**************************************************************************************/

/**************************************************************************************/

#include <I86.H>

#define 	DISP_CTRL_ADDR	0x0FFEA
#define		DISP_STAT_ADDR	0x0FFEA
#define		DISP_DATA_ADDR	0x0FFE8

typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef long int32_t;
typedef unsigned long uint32_t;

unsigned int nums[6] = { 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D };

/*uint16_t ReadData()
{
	outword(DISP_CTRL_ADDR, 0x040);
	return(inword(DISP_DATA_ADDR));
}*/

void main()
{
uint16_t key;
uint16_t cnt = 0;
uint16_t i;
unsigned int test;

	test = nums[1];

	/* Clear the display */
	outword(DISP_CTRL_ADDR, 0x0D3);
	for(i = 0; i < 100; i++);	
	outword(DISP_CTRL_ADDR, 0x087);			/* output WRITE DISPLAY to control word */
	for(i = 0; i < 100; i++);
	outword(DISP_DATA_ADDR, test);		/* output the new display data */
	
	while(1)
	{
		/* Has a key been pressed? */
/*		if((inword(DISP_STAT_ADDR) & 0x000F) != 0)*/
/*		{*/
			/* increment the counter but make sure it stays in the range of 0 - 6 */
/*			cnt++;
			if(cnt >= 0x07)
			{
				cnt = 1;
			}*/
			
/*			key = ReadData();*/						/* read the key data */
/*			outword(DISP_CTRL_ADDR, 0x087);*/			/* output WRITE DISPLAY to control word */
/*			outword(DISP_DATA_ADDR, nums[cnt-1]);*/		/* outputthe new display data */

/*		}*/
		
		
	}
}
