
#include <stdio.h>
#include <string.h>
#include "sixel.h"
/*#include "types.h"*/

int main(void)
{
   
    /* clear the screen and position the cursor to home */
	printf("%c[2J%c[H\r\n\r\n", (char)27, (char)27);
    printf("Hello World!\r\n");
    
    SetSixelMode();
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~$-");
    
    SetTextMode();
    
    /*printf("\r\n\r\n");*/

    return 0 ;
}
