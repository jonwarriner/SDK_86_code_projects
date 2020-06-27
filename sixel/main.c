
#include <stdio.h>
#include <string.h>
#include "sixel.h"
#include "types.h"

int main(void)
{
   
    /* clear the screen and position the cursor to home */
    printf("%c[2J%c[H\r\n\r\n", (char)27, (char)27);
    printf("This is text!\r\n");
    
    setSixelMode();
    
    /*printf("~~~~~~~~~~~~~~~~~~~~~~~~~$-");*/
    sixDrawLine(0, 25);
    sixDrawLine(15, 40);
    sixDrawLine(5, 50);
    sixDrawLine(75, 25);

    
    setTextMode();
    
    printf("This is also text!\r\n");

    return 0 ;
}
