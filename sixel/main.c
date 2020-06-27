/*****************************************************************************
* Copyright (C) 2019 by Jon Warriner
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Jon Warriner and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/**
* @file main.c
* @brief main file for the memory test project.  
*
* This source file provides the main() function for the
* memory test project.  
*
* @author Jon Warriner
* @date February 14, 2019
* @version 1.0
*
*/

#include <stdio.h>
#include <string.h>
/*#include "types.h"*/

int main(void)
{
   
    printf("%c[2J%c[H\r\n\r\n", (char)27, (char)27);
    printf("Hello World!\r\n");
    
    printf("%cPq", (char)27);		/* enter Sixel mode */
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~$-");
    
    printf("%c\\", (char)27);		/* back to text mode */
    
    printf("\r\n\r\n");

    return 0 ;
}
