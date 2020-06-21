
#include "Intl8279.h"


/* Initialize Intel 8279 Programmable Keyboard/Display Interface */
void Init_8279()
{
	/* The 8279 is driven by the peripheral clock (PCLK) on the SDK-86 board.	*/
	/* The main crystal on the board oscillates at 14.7456MHz and feeds into	*/
	/* the 8284 Clock Generator chip.  The 8284 divides the crystal freqquency	*/
	/* by 3 to generate CLK at 4.9152MHz.  The clock is further divided by 2 to	*/
	/* produce a 2.4576MHz PCLK.												*/
	/* We will set the 8279 divider to /25 for an internal clock of 98.304kHz.	*/
	/* The target clock period is 10us to acheive the following 8279 specified	*/
	/* timing.																	*/
	/* Keyboard Scan Time: 5.1ms												*/
	/* Keyboard Debounce Time: 10.3ms											*/
	/* Key Scan Time: 80us														*/
	/* Display Scan Time: 10.3ms												*/
	/* Digit-on Time: 480us														*/
	/* Blanking Time: 160us														*/
	INTL8279_CLK_PRESCALE(0x19);
	
	/* Set Keyboard and Display mode */
	INTL8279_KEY_DISP_MODE(DD_LEFT_ENTRY_8_BIT_8_CHAR, KKK_ENC_SCAN_KEY_2_KEY_LOCK);
	
	/* Clear the display and FIFO status */
	INTL8279_CLEAR(CD_ALL_ZEROS, 1, 1);
	
	/* After a clear we need to wait for the display to be available.  This should take ~160us */
	while(INTL8279_FIFO_STATUS & INTL8279_FIFO_STATUS_DU_MASK);
}