
#include "digits.h"

/*********************************************************************************
		   (a)
		--------
	   |        |
   (f) |        | (b)
	   |        |
	   |   (g)  |
	    --------
	   |        |
   (e) |        | (c)
	   |        |
	   |        |
	    --------   O  (DP)
		   (d)
**********************************************************************************/

/* A3 A2 A1 A0 B3 B2 B1 B0 		 8279 output bit	*/
/* DP  g  f  e  d  c  b  a       segment			*/
/*  |  |  |  |  |  |  |  |							*/
/*  |  |  |  |  |  |  |  -------> bit 0				*/
/*  |  |  |  |  |  |  ----------> bit 1				*/
/*  |  |  |  |  |  -------------> bit 2				*/
/*  |  |  |  |  ----------------> bit 3				*/
/*  |  |  |  -------------------> bit 4				*/
/*  |  |  ----------------------> bit 5				*/
/*  |  -------------------------> bit 6				*/
/*  ----------------------------> bit 7				*/

uint8_t seven_seg_digits_decode_gfedcba[91]= {
/*	SP    !     "     #     $     %     &     '			*/
	0x00, 0x82, 0x22, 0x00, 0x00, 0x00, 0x00, 0x20,
/*	(     )     *     +     ,     -     .     /			*/
	0x00, 0x00, 0x00, 0x00, 0x10, 0x40, 0x80, 0x00,
/*  0     1     2     3     4     5     6     7			*/
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
/*	8     9     :     ;     <     =     >     ?			*/
	0x7F, 0x6F, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00,
/*  @     A     B     C     D     E     F     G			*/
    0x00, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x3D,
/*  H     I     J     K     L     M     N     O			*/
    0x76, 0x30, 0x1E, 0x00, 0x38, 0x00, 0x54, 0x3F,
/*	P     Q     R     S     T     U     V     W			*/
	0x73, 0x67, 0x50, 0x6D, 0x78, 0x3E, 0x00, 0x00,
/*  X     Y     Z     [     \     ]     ^     _			*/
    0x00, 0x6E, 0x5B, 0x00, 0x00, 0x00, 0x00, 0x08, 
/*  `     a     b     c     d     e     f     g			*/
    0x20, 0x5F, 0x7C, 0x58, 0x5E, 0x79, 0x71, 0x3D,
/*	h     i     j     k     l     m     n     o			*/
	0x74, 0x30, 0x1E, 0x00, 0x06, 0x00, 0x54, 0x5C,
/*  p     q     r     s     t     u     v     w			*/
    0x73, 0x67, 0x50, 0x6D, 0x78, 0x1C, 0x00, 0x00, 
/*  x     y     z     									*/
    0x00, 0x6E, 0x5B
};

/* Invalid letters are mapped to all segments off (0x00). */
uint8_t decode_7seg(uint8_t chr)
{ /* assuming implementation uses ASCII */
    if (chr > (uint8_t)'z')
        return 0x00;
    return seven_seg_digits_decode_gfedcba[chr - ' '];
}

