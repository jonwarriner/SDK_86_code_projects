#ifndef __INTL8251_H__
#define __INTL8251_H__

#include "types.h"
#include <I86.H>

#define INTL8251A_RD_DATA_IO_BASE		0xFFF0
#define INTL8251A_WR_DATA_IO_BASE		0xFFF0
#define INTL8251A_STATUS_IO_BASE		0xFFF2
#define INTL8255A_CNTRL_IO_BASE			0xFFF2

/* Define bits in Mode Instruction (ASYNC) */
/* MSB                  LSB							*/
/* |                     |							*/
/* V                     V							*/
/* S2 S1 EP PEN L2 L1 B2 B1							*/
/* |   |  |  |  |   | |  |							*/
/* -----  |  |  ----- ----							*/
/*   |    |  |	  |    |							*/
/*   |    |  |    |    ---------> Baud Rate Factor	*/
/*   |    |  |    --------------> Character Length	*/
/*   |    |  -------------------> Parity Enable		*/
/*   |    ----------------------> Even Parity		*/
/*   ---------------------------> Stop Bits			*/

/* define Baud Rate bit combinations				*/
/* B2 B1											*/
/* |   |											*/
/* -----											*/
/*   |												*/
/* 0   0   SYNC Mode								*/
/* 0   1   1X										*/
/* 1   0   16X										*/
/* 1   1   64X										*/
#define BAUD_SYNC		(0x0)	/* not really valid in ASYNC mode */
#define BAUD_1X			(0x1)
#define BAUD_16X		(0x2)
#define BAUD_64X		(0x3)

#define INTL8255_ASYNC_MODE_BAUD_MASK	(0x03)
#define INTL8255_ASYNC_MODE_BAUD_SHIFT	(0)
#define INTL8255_ASYNC_MODE_BAUD(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_ASYNC_MODE_BAUD_SHIFT)) & INTL8255_ASYNC_MODE_BAUD_MASK)

/* define Character Length bit combinations			*/
/* L2 L1											*/
/* |   |											*/
/* -----											*/
/*   |												*/
/* 0   0   5 bits									*/
/* 0   1   6 bits									*/
/* 1   0   7 bits									*/
/* 1   1   8 bits									*/
#define CHAR_LEN_5_BITS		(0x0)
#define CHAR_LEN_6_BITS		(0x1)
#define CHAR_LEN_7_BITS		(0x2)
#define CHAR_LEN_8_BITS		(0x3)

#define INTL8255_ASYNC_MODE_CHAR_MASK	(0x0C)
#define INTL8255_ASYNC_MODE_CHAR_SHIFT	(2)
#define INTL8255_ASYNC_MODE_CHAR(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_ASYNC_MODE_CHAR_SHIFT)) & INTL8255_ASYNC_MODE_CHAR_MASK)

/* Define Parity Enable								*/
#define PARITY_DISABLE		(0x0)
#define PARITY_ENABLE		(0x1)

#define INTL8255_ASYNC_MODE_PEN_MASK	(0x10)
#define INTL8255_ASYNC_MODE_PEN_SHIFT	(4)
#define INTL8255_ASYNC_MODE_PEN(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_ASYNC_MODE_PEN_SHIFT)) & INTL8255_ASYNC_MODE_PEN_MASK)

/* Define Even Parity								*/
#define ODD_PARITY			(0x0)
#define EVEN_PARITY			(0x1)

#define INTL8255_ASYNC_MODE_EP_MASK		(0x20)
#define INTL8255_ASYNC_MODE_EP_SHIFT	(5)
#define INTL8255_ASYNC_MODE_EP(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_ASYNC_MODE_EP_SHIFT)) & INTL8255_ASYNC_MODE_EP_MASK)

/* define Stop bit combinations						*/
/* S2 S1											*/
/* |   |											*/
/* -----											*/
/*   |												*/
/* 0   0   Invalid									*/
/* 0   1   1 bit									*/
/* 1   0   1 1/2 bits								*/
/* 1   1   2 bits									*/
#define STOP_1_BIT		(0x1)
#define STOP_1_HALF_BIT	(0x2)
#define STOP_2_BITS		(0x3)

#define INTL8255_ASYNC_MODE_STOP_MASK	(0xC0)
#define INTL8255_ASYNC_MODE_STOP_SHIFT	(6)
#define INTL8255_ASYNC_MODE_STOP(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_ASYNC_MODE_STOP_SHIFT)) & INTL8255_ASYNC_MODE_STOP_MASK)

#define INTL8255_ASYNC_MODE(B, L, PEN, EP, S)			(outbyte(INTL8255A_CNTRL_IO_BASE, INTL8255_ASYNC_MODE_BAUD(B) | INTL8255_ASYNC_MODE_CHAR(L) | INTL8255_ASYNC_MODE_PEN(PEN) | INTL8255_ASYNC_MODE_EP(EP) | INTL8255_ASYNC_MODE_STOP(S)))

/* Only using ASYNC mode for now so not defining SYNC mode*/

/* Define bits in Command Instruction						*/
/* MSB                       LSB							*/
/* |                          |								*/
/* V                          V								*/
/* EH IR RTS ER SBRK RxE DTR TxEN							*/
/* |  |   |  |   |    |   |   |								*/
/* |  |   |  |   |    |   |   -------> Transmit Enable		*/
/* |  |   |  |   |    |   -----------> Data Terminal Ready	*/
/* |  |   |  |   |    ---------------> Receive Enable		*/
/* |  |   |  |   --------------------> Send Break Char		*/
/* |  |   |  ------------------------> Error Reset			*/
/* |  |   ---------------------------> Request to Send		*/
/* |  -------------------------------> Internal Reset		*/
/* ----------------------------------> Enter Hunt Mode		*/
#define INTL8255_CMD_TXEN_MASK		(0x01)
#define INTL8255_CMD_TXEN_SHIFT		(0)
#define INTL8255_CMD_TXEN(x)		(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_TXEN_SHIFT)) & INTL8255_CMD_TXEN_MASK)

#define INTL8255_CMD_DTR_MASK		(0x02)
#define INTL8255_CMD_DTR_SHIFT		(1)
#define INTL8255_CMD_DTR(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_DTR_SHIFT)) & INTL8255_CMD_DTR_MASK)

#define INTL8255_CMD_RXE_MASK		(0x04)
#define INTL8255_CMD_RXE_SHIFT		(2)
#define INTL8255_CMD_RXE(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_RXE_SHIFT)) & INTL8255_CMD_RXE_MASK)

#define INTL8255_CMD_SBRK_MASK		(0x08)
#define INTL8255_CMD_SBRK_SHIFT		(3)
#define INTL8255_CMD_SBRK(x)		(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_SBRK_SHIFT)) & INTL8255_CMD_SBRK_MASK)

#define INTL8255_CMD_ER_MASK		(0x10)
#define INTL8255_CMD_ER_SHIFT		(4)
#define INTL8255_CMD_ER(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_ER_SHIFT)) & INTL8255_CMD_ER_MASK)

#define INTL8255_CMD_RTS_MASK		(0x20)
#define INTL8255_CMD_RTS_SHIFT		(5)
#define INTL8255_CMD_RTS(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_RTS_SHIFT)) & INTL8255_CMD_RTS_MASK)

#define INTL8255_CMD_IR_MASK		(0x40)
#define INTL8255_CMD_IR_SHIFT		(6)
#define INTL8255_CMD_IR(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_IR_SHIFT)) & INTL8255_CMD_IR_MASK)

#define INTL8255_CMD_EH_MASK		(0x80)
#define INTL8255_CMD_EH_SHIFT		(7)
#define INTL8255_CMD_EH(x)			(((uint8_t)(((uint8_t)(x)) << INTL8255_CMD_EH_SHIFT)) & INTL8255_CMD_EH_MASK)

#define INTL8255_CMD(CMD)			(outbyte(INTL8255A_CNTRL_IO_BASE, CMD))


void Init_8251A();

#endif /* __INTL8251_H__ */
