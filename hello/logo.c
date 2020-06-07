
#include "logo.h"

uint8_t swan_logo[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, '/r', '/n', 0};

void print_logo()
{
	uint16_t i;
	
	for(i = 0; i < sizeof(swan_logo); i++)
	{
		putchar(swan_logo[i]);
	}
}
