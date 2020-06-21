#include "Intl8251.h"

/* Local copy of the 8251A command register so we can manipulate bits */
uint8_t cmd_8251A = 0;

void Intl8251A_delay()
{
}

/* Initialize Intel 8251A Programmable Communication Interface */
void Init_8251A()
{
	uint8_t i;
	/*****************************************************************************************/
	/* According to the latest datasheet the state in the sequence of mode */
	/* and command instructions could be unknown after power up.  The      */
	/* recommended sequence is to write 3 zeros to ensure we are in the    */
	/* command instruction state and then assert a reset.                  */
	/* This should also allow us to reinitialize the 8251A after loading   */
	/* from the serial monitor.                                            */
	for(i =0; i < 4; i++)
	{
		INTL8251A_ASYNC_MODE(0, 0, 0, 0, 0);
		Intl8251A_delay();
	}
	
	INTL8251A_CMD(INTL8251A_CMD_IR(1));
	Intl8251A_delay();
	/*****************************************************************************************/
	
	/* Now we can set the mode */
	INTL8251A_ASYNC_MODE(BAUD_64X, CHAR_LEN_8_BITS, PARITY_DISABLE, ODD_PARITY, STOP_2_BITS);
	Intl8251A_delay();
	
	/* Now set the desired command bits */
	/* 8251A data sheet says Error Reset must be perormed whenever RxEnable is programmed */
	cmd_8251A = INTL8251A_CMD_TXEN(1) | INTL8251A_CMD_DTR(1) | INTL8251A_CMD_RXE(1) | INTL8251A_CMD_RTS(1);
	INTL8251A_CMD(cmd_8251A);
	Intl8251A_delay();
}
