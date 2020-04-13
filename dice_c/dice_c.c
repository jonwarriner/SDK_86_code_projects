#include <I86.H>

#define 	DISP_CTRL_ADDR	0x0FFEA
#define		DISP_STAT_ADDR	0x0FFEA
#define		DISP_DATA_ADDR	0x0FFE8

short READATA()
{
	outword(DISP_CTRL_ADDR, 0x040);
	return(inword(DISP_DATA_ADDR));
}

void main()
{
	short i;
	short cnt;
	
	/**((short *)DISP_CTRL_ADDR) = 0x0D3;*/
	outword(DISP_CTRL_ADDR, 0x0D3);
	
	while((inword(DISP_STAT_ADDR) & 0x000F) == 0);
	
	
}
