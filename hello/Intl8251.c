#include "Intl8251.h"

/* Local copy of the 8251A command register so we can manipulate bits */
uint8_t cmd_8251A = 0;


/* Initialize Intel 8251A Programmable Communication Interface */
void Init_8251A()
{
	/* If this program was loaded from the serial monitor then the 8251A will already be cofigured. */
	/* Set the Internal Reset so that we can reconfigure it out way.								*/
	INTL8255_CMD(INTL8255_CMD_IR(1));
	
	/* Now we can set the mode */
	INTL8255_ASYNC_MODE(BAUD_64X, CHAR_LEN_8_BITS, PARITY_DISABLE, ODD_PARITY, STOP_2_BITS);
	
	/* Now set the desired command bits */
	cmd_8251A = 
}
