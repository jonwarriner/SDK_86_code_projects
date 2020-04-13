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

uint16_t ReadData()
{
	outword(DISP_CTRL_ADDR, 0x040);
	return(inword(DISP_DATA_ADDR));
}
