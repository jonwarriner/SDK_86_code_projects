#ifndef __INTL8279_H__
#define __INTL8279_H__

#include "types.h"
#include <I86.H>

#define INTL8279_RAM_IO_BASE			0xFFE8
#define INTL8279_STAT_CMD_IO_BASE		0xFFEA

/* Define bits in Keyboard/Display Mode Set */
/* MSB           LSB						*/
/* |             |							*/
/* V             V							*/
/* 0 0 0 D D K K K							*/
/* |   | | | |   |							*/
/* ----- --- -----							*/
/*   |    |    |							*/
/*   |    |    --------> Keyboard Mode		*/
/*   |    -------------> Display Mode		*/
/*   ------------------> Command Code		*/
/* DD - Display Mode						*/
#define DD_LEFT_ENTRY_8_BIT_8_CHAR		0
#define DD_LEFT_ENTRY_8_BIT_16_CHAR		1
#define DD_RIGHT_ENTRY_8_BIT_8_CHAR		2
#define DD_RIGHT_ENTRY_8_BIT_16_CHAR	3
/* KKK Keyboard Mode						*/
#define KKK_ENC_SCAN_KEY_2_KEY_LOCK		0		/* Encoded Scan Keyboard - 2-Key Lockout */
#define KKK_DEC_SCAN_KEY_2_KEY_LOCK		1		/* Decoded Scan Keyboard - 2-Key Lockout */
#define KKK_ENC_SCAN_KEY_N_KEY_ROLL		2		/* Encoded Scan Keyboard - N-Key Rollover */
#define KKK_DEC_SCAN_KEY_N_KEY_ROLL		3		/* Decoded Scan Keyboard - N-Key Rollover */
#define KKK_ENC_SCAN_SENOR_MATRIX		4		/* Encoded Scan Sensor Matrix			  */
#define KKK_DEC_SCAN_SENOR_MATRIX		5		/* Decoded Scan Sensor Matrix			  */
#define KKK_STR_IN_ENC_DISP_SCAN		6		/* Strobed Input, Encoded Display Scan    */
#define KKK_STR_IN_DEC_DISP_SCAN		7		/* Strobed Input, Decoded Display Scan    */

#define INTL8279_DISP_MODE_K_MASK		(0x07)
#define INTL8279_DISP_MODE_K_SHIFT		(0)
#define INTL8279_DISP_MODE_K(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_DISP_MODE_K_SHIFT)) & INTL8279_DISP_MODE_K_MASK)
#define INTL8279_DISP_MODE_D_MASK		(0x18)
#define INTL8279_DISP_MODE_D_SHIFT		(3)
#define INTL8279_DISP_MODE_D(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_DISP_MODE_D_SHIFT)) & INTL8279_DISP_MODE_D_MASK)
#define INTL8279_DISP_MODE_CMD_MASK		(0x00)
#define INTL8279_DISP_MODE_CMD_SHIFT	(5)
#define INTL8279_DISP_MODE_CMD			(((uint8_t)(((uint8_t)(0)) << INTL8279_DISP_MODE_CMD_SHIFT)) & INTL8279_DISP_MODE_CMD_MASK)

#define INTL8279_KEY_DISP_MODE(DD, KKK)	(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_DISP_MODE_CMD | INTL8279_DISP_MODE_D(DD) | INTL8279_DISP_MODE_K(KKK)))

/* Define bits in 8279 Clock Prescaler */
/* MSB           LSB									*/
/* |             |										*/
/* V             V										*/
/* 0 0 1 P P P P P										*/
/* |   | |       |										*/
/* ----- ---------										*/
/*   |       |											*/
/*   |       -------------> Clock Prescaler (2 to 31)	*/
/*   ---------------------> Command Code				*/
#define INTL8279_PROG_CLOCK_P_MASK			(0x1F)
#define INTL8279_PROG_CLOCK_P_SHIFT			(0)
#define INTL8279_PROG_CLOCK_P(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_PROG_CLOCK_P_SHIFT)) & INTL8279_PROG_CLOCK_P_MASK)
#define INTL8279_PROG_CLOCK_CMD_MASK		(0x20)
#define INTL8279_PROG_CLOCK_CMD_SHIFT		(5)
#define INTL8279_PROG_CLOCK_CMD				(((uint8_t)(((uint8_t)(0x1)) << INTL8279_PROG_CLOCK_CMD_SHIFT)) & INTL8279_PROG_CLOCK_CMD_MASK)

#define INTL8279_CLK_PRESCALE(PPPPP)		(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_PROG_CLOCK_CMD | INTL8279_PROG_CLOCK_P(PPPPP)))

/* Define bits for Read FIFO/Sensor RAM		*/
/* This command is used to specify that the	*/
/* source of data reads by the CPU is the	*/
/* FIFO/Sensor RAM.							*/
/* MSB            LSB						*/
/* |              |							*/
/* V              V							*/
/* 0 1 0 AI X A A A							*/
/* |   |  | | |   |							*/
/* -----  | | -----							*/
/*   |    | |   |							*/
/*   |    | |   -----------> Sensor Row to Read (Only used in Sensor Matrix Mode)	*/
/*   |    | ---------------> Reserved												*/
/*   |    -----------------> Auto-Increment (Only used in Sensor Matrix Mode)		*/
/*   ----------------------> Command Code											*/
#define INTL8279_READ_FIFO_A_MASK		(0x07)
#define INTL8279_READ_FIFO_A_SHIFT		(0)
#define INTL8279_READ_FIFO_A(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_READ_FIFO_A_SHIFT)) & INTL8279_READ_FIFO_A_MASK)
#define INTL8279_READ_FIFO_X_MASK		(0x08)
#define INTL8279_READ_FIFO_X_SHIFT		(3)
#define INTL8279_READ_FIFO_AI_MASK		(0x10)
#define INTL8279_READ_FIFO_AI_SHIFT	(4)
#define INTL8279_READ_FIFO_AI(x)		(((uint8_t)(((uint8_t)(x)) << INTL8279_READ_FIFO_AI_SHIFT)) & INTL8279_READ_FIFO_AI_MASK)
#define INTL8279_READ_FIFO_CMD_MASK		(0x40)
#define INTL8279_READ_FIFO_CMD_SHIFT	(5)
#define INTL8279_READ_FIFO_CMD			(((uint8_t)(((uint8_t)(0x2)) << INTL8279_READ_FIFO_CMD_SHIFT)) & INTL8279_READ_FIFO_CMD_MASK)

#define INTL8279_READ_FIFO(AI, A)	(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_READ_FIFO_CMD | INTL8279_READ_FIFO_AI(AI) | INTL8279_READ_FIFO_A(A)))

/* Define the bits for Read Display RAM			*/
/* This command is used to specify the display	*/
/* RAM as the data source for CPU data reads.	*/
/* MSB            LSB							*/
/* |              |								*/
/* V              V								*/
/* 0 1 1 AI A A A A								*/
/* |   |  | |     |								*/
/* -----  | -------								*/
/*   |    |    |								*/
/*   |    |    -------------> Character to Read	*/
/*   |    ------------------> Auto-increment	*/
/*   -----------------------> Command Code		*/
#define INTL8279_READ_DISP_RAM_A_MASK		(0x0F)
#define INTL8279_READ_DISP_RAM_A_SHIFT		(0)
#define INTL8279_READ_DISP_RAM_A(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_READ_DISP_RAM_A_SHIFT)) & INTL8279_READ_DISP_RAM_A_MASK)
#define INTL8279_READ_DISP_RAM_AI_MASK		(0x10)
#define INTL8279_READ_DISP_RAM_AI_SHIFT		(4)
#define INTL8279_READ_DISP_RAM_AI(x)		(((uint8_t)(((uint8_t)(x)) << INTL8279_READ_DISP_RAM_AI_SHIFT)) & INTL8279_READ_DISP_RAM_AI_MASK)
#define INTL8279_READ_DISP_RAM_CMD_MASK		(0x60)
#define INTL8279_READ_DISP_RAM_CMD_SHIFT	(5)
#define INTL8279_READ_DISP_RAM_CMD			(((uint8_t)(((uint8_t)(0x3)) << INTL8279_READ_DISP_RAM_CMD_SHIFT)) & INTL8279_READ_DISP_RAM_CMD_MASK)

#define INTL8279_READ_DISP_RAM(AI, A)		(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_READ_DISP_RAM_CMD | INTL8279_READ_DISP_RAM_AI(AI) | INTL8279_READ_DISP_RAM_A(A)))

/* Define the bits for Write Display RAM			*/
/* This command is used to specify the display		*/
/* character that the CPU will write to next.		*/
/* MSB            LSB								*/
/* |              |									*/
/* V              V									*/
/* 1 0 0 AI A A A A									*/
/* |   |  | |     |									*/
/* -----  | -------									*/
/*   |    |    |									*/
/*   |    |    -------------> Character to Write	*/
/*   |    ------------------> Auto-increment		*/
/*   -----------------------> Command Code			*/
#define INTL8279_WRITE_DISP_RAM_A_MASK		(0x0F)
#define INTL8279_WRITE_DISP_RAM_A_SHIFT		(0)
#define INTL8279_WRITE_DISP_RAM_A(x)		(((uint8_t)(((uint8_t)(x)) << INTL8279_WRITE_DISP_RAM_A_SHIFT)) & INTL8279_WRITE_DISP_RAM_A_MASK)
#define INTL8279_WRITE_DISP_RAM_AI_MASK		(0x10)
#define INTL8279_WRITE_DISP_RAM_AI_SHIFT	(4)
#define INTL8279_WRITE_DISP_RAM_AI(x)		(((uint8_t)(((uint8_t)(x)) << INTL8279_WRITE_DISP_RAM_AI_SHIFT)) & INTL8279_WRITE_DISP_RAM_AI_MASK)
#define INTL8279_WRITE_DISP_RAM_CMD_MASK	(0x80)
#define INTL8279_WRITE_DISP_RAM_CMD_SHIFT	(5)
#define INTL8279_WRITE_DISP_RAM_CMD			(((uint8_t)(((uint8_t)(0x4)) << INTL8279_WRITE_DISP_RAM_CMD_SHIFT)) & INTL8279_WRITE_DISP_RAM_CMD_MASK)

#define INTL8279_WRITE_DISP_RAM(AI, A)		(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_WRITE_DISP_RAM_CMD | INTL8279_WRITE_DISP_RAM_AI(AI) | INTL8279_WRITE_DISP_RAM_A(A)))

/* Display Write Inhibit/Blanking								*/
/* MSB               LSB										*/
/* |                 |											*/
/* V                 V											*/
/* 1 0 1 X IW IW BL BL											*/
/* |   | | A   B A   B											*/
/* |   | | |   | |   |											*/
/* ----- | ----- -----											*/
/*   |   |   |     |											*/
/*   |   |   |     ----------> Blanking (nibble A or B)			*/
/*   |   |   ----------------> Inhibit Writing (nibble A or B)	*/
/*   |   --------------------> Reserved							*/
/*   ------------------------> Command Code						*/
#define INTL8279_DISP_IW_BL_BL_MASK			(0x03)
#define INTL8279_DISP_IW_BL_BL_SHIFT		(0)
#define INTL8279_DISP_IW_BL_BL(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_DISP_IW_BL_BL_SHIFT)) & INTL8279_DISP_IW_BL_BL_MASK)
#define INTL8279_DISP_IW_BL_IW_MASK			(0x03)
#define INTL8279_DISP_IW_BL_IW_SHIFT		(2)
#define INTL8279_DISP_IW_BL_IW(x)			(((uint8_t)(((uint8_t)(x)) << INTL8279_DISP_IW_BL_IW_SHIFT)) & INTL8279_DISP_IW_BL_IW_MASK)
#define INTL8279_DISP_IW_BL_CMD_MASK		(0x0A)
#define INTL8279_DISP_IW_BL_SHIFT_CMD		(5)
#define INTL8279_DISP_IW_BL_CMD				(((uint8_t)(((uint8_t)(0x5)) << INTL8279_DISP_IW_BL_CMD_SHIFT)) & INTL8279_DISP_IW_BL_CMD_MASK)

#define INTL8279_DISP_IW_BL(IW, BL)			(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_DISP_IW_BL_CMD | INTL8279_DISP_IW_BL_IW(IW) | INTL8279_DISP_IW_BL_BL(BL)))

/* Clear														*/
/* MSB                LSB										*/
/* |                  |											*/
/* V                  V											*/
/* 1 1 0 CD CD CD CF CA											*/
/* |   | |      |  |  |											*/
/* ----- --------  |  |											*/
/*   |      |      |  --------> Clear All						*/
/*   |      |      -----------> Clear FIFO Status				*/
/*   |      ------------------> Clear Display					*/
/*   -------------------------> Command Code					*/
#define INTL8279_CLEAR_CA_MASK				(0x01)
#define INTL8279_CLEAR_CA_SHIFT				(0)
#define INTL8279_CLEAR_CA(x)				(((uint8_t)(((uint8_t)(x)) << INTL8279_CLEAR_CA_SHIFT)) & INTL8279_CLEAR_CA_MASK)
#define INTL8279_CLEAR_CF_MASK				(0x02)
#define INTL8279_CLEAR_CF_SHIFT				(1)
#define INTL8279_CLEAR_CF(x)				(((uint8_t)(((uint8_t)(x)) << INTL8279_CLEAR_CF_SHIFT)) & INTL8279_CLEAR_CF_MASK)
#define INTL8279_CLEAR_CD_MASK				(0x1C)
#define INTL8279_CLEAR_CD_SHIFT				(2)
#define INTL8279_CLEAR_CD(x)				(((uint8_t)(((uint8_t)(x)) << INTL8279_CLEAR_CD_SHIFT)) & INTL8279_CLEAR_CD_MASK)
#define INTL8279_CLEAR_CMD_MASK				(0xC0)
#define INTL8279_CLEAR_CMD_SHIFT			(5)
#define INTL8279_CLEAR_CMD					(((uint8_t)(((uint8_t)(0x6)) << INTL8279_CLEAR_CMD_SHIFT)) & INTL8279_CLEAR_CMD_MASK)

/* define CD bit combinations								*/
/* CD CD CD													*/
/* |  |   |													*/
/* |  -----													*/
/* |    |													*/
/* |  0   x   All Zeros (x = Don't Care)					*/
/* |  1   0   AB = Hex 20 (0010 0000)						*/
/* |  1   1   All Ones										*/
/* ---------> Enable clear display when = 1 (or by CA = 1)	*/
#define CD_ALL_ZEROS	(0x4)
#define CD_HEX_20		(0x6)
#define CD_ALL_ONES		(0x7)

#define INTL8279_CLEAR(CD, CF, CA)			(outbyte(INTL8279_STAT_CMD_IO_BASE, INTL8279_CLEAR_CMD | INTL8279_CLEAR_CD(CD) | INTL8279_CLEAR_CF(CF) | INTL8279_CLEAR_CA(CA)))

/* Define bits in FIFO Status */
/* MSB              LSB							*/
/* |                |							*/
/* V                V							*/
/* DU S/E O U F N N N */
/*  |   | | | | |   | */
/*  |   | | | | ----- */
/*  |   | | | |   |   */
/*  |   | | | |   ---------> (bit 0:2) Number of characters in FIFO 					*/
/*  |   | | | -------------> (bit 3)   FIFO Full										*/
/*  |   | | ---------------> (bit 4)   Error: Underrun									*/
/*  |   | -----------------> (bit 5)   Error: Overrun									*/
/*  |   -------------------> (bit 6)   Sensor Closure/Error Flag for Multiple Closures	*/
/*  -----------------------> (bit 7)   Display Unavailable								*/
#define INTL8279_FIFO_STATUS_N_MASK		(0x07)
#define INTL8279_FIFO_STATUS_N_SHIFT	(0)
#define INTL8279_FIFO_STATUS_F_MASK		(0x08)
#define INTL8279_FIFO_STATUS_F_SHIFT	(3)
#define INTL8279_FIFO_STATUS_U_MASK		(0x10)
#define INTL8279_FIFO_STATUS_U_SHIFT	(4)
#define INTL8279_FIFO_STATUS_O_MASK		(0x20)
#define INTL8279_FIFO_STATUS_O_SHIFT	(5)
#define INTL8279_FIFO_STATUS_SE_MASK	(0x40)
#define INTL8279_FIFO_STATUS_SE_SHIFT	(6)
#define INTL8279_FIFO_STATUS_DU_MASK	(0x80)
#define INTL8279_FIFO_STATUS_DU_SHIFT	(7)

#define INTL8279_FIFO_STATUS				(inbyte(INTL8279_STAT_CMD_IO_BASE))

/* Intel 8279 Data Read */
#define INTL8279_DATA_READ					(inbyte(INTL8279_RAM_IO_BASE))

/* Intel 8279 Data Write */
#define INTL8279_DATA_WRITE(x)				(outbyte(INTL8279_RAM_IO_BASE, x))

void Init_8279();

#endif /* __INTL8279_H__ */
