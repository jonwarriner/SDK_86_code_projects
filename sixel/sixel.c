#include "sixel.h"

void setSixelMode()
{
    printf("%cPq", (char)27);
}

void setTextMode()
{
    printf("%c\\", (char)27);
}

void sixDrawLine(uint16_t st, uint16_t lp)
{
    uint16_t i;
    
    /* print blanks until we get to the starting point */
    for(i = 0; i < st; i++)
    {
        printf("?");
    }

    /* now print the line */
    for(i = 0; i < lp; i++)
    {
        printf("~");
    }
    
    printf(SIX_CRLF);
}
