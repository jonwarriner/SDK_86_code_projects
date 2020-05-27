#ifndef __INTL8255_H__
#define __INTL8255_H__

#include "types.h"
#include <I86.H>

#define INTL8255A_P2A_IO_BASE			0xFFF8
#define INTL8255A_P1A_IO_BASE			0xFFF9
#define INTL8255A_P2B_IO_BASE			0xFFFA
#define INTL8255A_P1B_IO_BASE			0xFFFB
#define INTL8255A_P2C_IO_BASE			0xFFFC
#define INTL8255A_P1C_IO_BASE			0xFFFD
#define INTL8255A_P2CTRL_IO_BASE		0xFFFE
#define INTL8255A_P1CTRL_IO_BASE		0xFFFF

/* Define Control Word settings for Mode 0 (Basic Input/Output				*/
#define INTL8255A_MODE0_0				(0x80)		/* PA - output, PB - output, PC[7:4] - output, PC[3:0] output */
#define INTL8255A_MODE0_1				(0x81)		/* PA - output, PB - output, PC[7:4] - output, PC[3:0] input */
#define INTL8255A_MODE0_2				(0x82)		/* PA - output, PB - input, PC[7:4] - output, PC[3:0] output */
#define INTL8255A_MODE0_3				(0x83)		/* PA - output, PB - input, PC[7:4] - output, PC[3:0] input */
#define INTL8255A_MODE0_4				(0x88)		/* PA - output, PB - output, PC[7:4] - input, PC[3:0] output */
#define INTL8255A_MODE0_5				(0x89)		/* PA - output, PB - output, PC[7:4] - input, PC[3:0] input */
#define INTL8255A_MODE0_6				(0x8A)		/* PA - output, PB - input, PC[7:4] - input, PC[3:0] output */
#define INTL8255A_MODE0_7				(0x8B)		/* PA - output, PB - input, PC[7:4] - input, PC[3:0] input */
#define INTL8255A_MODE0_8				(0x90)		/* PA - input, PB - output, PC[7:4] - output, PC[3:0] output */
#define INTL8255A_MODE0_9				(0x91)		/* PA - input, PB - output, PC[7:4] - output, PC[3:0] input */
#define INTL8255A_MODE0_10				(0x92)		/* PA - input, PB - input, PC[7:4] - output, PC[3:0] output */
#define INTL8255A_MODE0_11				(0x93)		/* PA - input, PB - input, PC[7:4] - output, PC[3:0] input */
#define INTL8255A_MODE0_12				(0x98)		/* PA - input, PB - output, PC[7:4] - input, PC[3:0] output */
#define INTL8255A_MODE0_13				(0x99)		/* PA - input, PB - output, PC[7:4] - input, PC[3:0] input */
#define INTL8255A_MODE0_14				(0x9A)		/* PA - input, PB - input, PC[7:4] - input, PC[3:0] output */
#define INTL8255A_MODE0_15				(0x9B)		/* PA - input, PB - input, PC[7:4] - input, PC[3:0] input */

/* Define Control Word settings for Mode 1 (Strobed Input/Output)			*/
/* Not using now so not currently defined	*/

/* Define Control Word settings for Mode 2 (Strobed Bidirectional Bus I/O)	*/
/* Not using now so not currently defined	*/

/* Intel 8255A Control Word Write */
#define INTL8255A_P1_CNTL_WRITE(x)				(outbyte(INTL8255A_P1CTRL_IO_BASE, x))
#define INTL8255A_P2_CNTL_WRITE(x)				(outbyte(INTL8255A_P2CTRL_IO_BASE, x))

/* Intel 8255A Port Write */
/* Write to ports A, B, C of ports 1 and 2 individually */
#define INTL8255A_P1A_WRITE(x)					(outbyte(INTL8255A_P1A_IO_BASE, x))
#define INTL8255A_P1B_WRITE(x)					(outbyte(INTL8255A_P1B_IO_BASE, x))
#define INTL8255A_P1C_WRITE(x)					(outbyte(INTL8255A_P1C_IO_BASE, x))
#define INTL8255A_P2A_WRITE(x)					(outbyte(INTL8255A_P2A_IO_BASE, x))
#define INTL8255A_P2B_WRITE(x)					(outbyte(INTL8255A_P2B_IO_BASE, x))
#define INTL8255A_P2C_WRITE(x)					(outbyte(INTL8255A_P2C_IO_BASE, x))

/* Write to ports A, B, C of ports 1 and 2 simultaneously */
#define INTL8255A_P12A_WRITE(x)					(outword(INTL8255A_P2A_IO_BASE, x))
#define INTL8255A_P12B_WRITE(x)					(outword(INTL8255A_P2B_IO_BASE, x))
#define INTL8255A_P12C_WRITE(x)					(outword(INTL8255A_P2C_IO_BASE, x))

/* Intel 8255A Port Read */
/* Read from ports A, B, C of ports 1 and 2 individually */
#define INTL8255A_P1A_READ(x)					(inbyte(INTL8255A_P1A_IO_BASE, x))
#define INTL8255A_P1B_READ(x)					(inbyte(INTL8255A_P1B_IO_BASE, x))
#define INTL8255A_P1C_READ(x)					(inbyte(INTL8255A_P1C_IO_BASE, x))
#define INTL8255A_P2A_READ(x)					(inbyte(INTL8255A_P2A_IO_BASE, x))
#define INTL8255A_P2B_READ(x)					(inbyte(INTL8255A_P2B_IO_BASE, x))
#define INTL8255A_P2C_READ(x)					(inbyte(INTL8255A_P2C_IO_BASE, x))

/* Read from ports A, B, C of ports 1 and 2 simultaneously */
#define INTL8255A_P12A_READ(x)					(inword(INTL8255A_P2A_IO_BASE, x))
#define INTL8255A_P12B_READ(x)					(inword(INTL8255A_P2B_IO_BASE, x))
#define INTL8255A_P12C_READ(x)					(inword(INTL8255A_P2C_IO_BASE, x))

void Init_8255A();

#endif /* __INTL8255_H__ */
