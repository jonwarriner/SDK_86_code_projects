#include <I86.H>
#include "types.h"

#define 	DISP_CTRL_ADDR	0x0FFEA
#define		DISP_STAT_ADDR	0x0FFEA
#define		DISP_DATA_ADDR	0x0FFE8

uint16_t ReadData()
{
	uint16_t i;

	outword(DISP_CTRL_ADDR, 0x040);
	for(i = 0; i < 100; i++);	
	return(inword(DISP_DATA_ADDR));
}
