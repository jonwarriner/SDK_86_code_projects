
#include "keys.h"

/* Physical Keyboard Layout							*/

/* |---|---|---|---|---|---|
/* |RST|INT| C | D | E | F |						*/
/* |---|---|---|---|---|---|						*/
/* | + | - | 8 | 9 | A | B |						*/
/* |---|---|---|---|---|---|						*/
/* | : |REG| 4 | 5 | 6 | 7 |						*/    
/* |---|---|---|---|---|---|						*/
/* | , | . | 0 | 1 | 2 | 3 |						*/
/* |---|---|---|---|---|---|						*/


/* Electrical Keyboard Layout						*/
/* -------------------------> RL0 -					*/
/* | -----------------------> RL1  |				*/
/* | | ---------------------> RL2  |				*/
/* | | | -------------------> RL3  |				*/
/* | | | | -----------------> RL4  |-- Return Lines	*/
/* | | | | | ---------------> RL5  |				*/
/* | | | | | | -------------> RL6  |				*/
/* | | | | | | | -----------> RL7 -					*/
/* | | | | | | | |									*/
/* 0 1 2 3 4 5 6 7----------> SL0 -					*/
/* 8 9 A B C D E F----------> SL1  |--Scan Lines	*/
/* . , - + : r    ----------> SL2 -					*/

/* 8279 Scanned Keyboard Data Format				*/
/* CNTL SHIFT SCAN RETURN							*/
/* |  | |   | |  | |    |							*/
/* ---- ----- ---- ------							*/
/*  |     |    |     |    							*/
/*  |     |    |     -----------> bit 2:0			*/
/*  |     |     ----------------> bit 5:3			*/
/*  |     ----------------------> bit 6				*/
/*  ----------------------------> bit 7				*/

/* There are 22 keys total connected to the 8279.	*/
/* RST and INT are connected directly to the CPU.	*/
/* Create an array of ASCII representations for		*/
/* each key using the vaule read from the FIFO as	*/
/* an index.										*/
uint8_t keys[22] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', '.', ',', '-', '+', ':', 'r'};

/* Get ASCII equivalent of a key */
uint8_t ascii_key(uint8_t key)
{
    if (key > sizeof(keys))
        return 0x00;
    return keys[key];
}
