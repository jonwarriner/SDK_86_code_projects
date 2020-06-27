#include "sixel.h"

void setSixelMode()
{
    printf("%cPq", (char)27);
}

void setTextMode()
{
    printf("%c\\", (char)27);
}