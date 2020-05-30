#ifndef __INTL8251_H__
#define __INTL8251_H__

#include "types.h"
#include <I86.H>

#define INTL8251A_RD_DATA_IO_BASE		0xFFF0
#define INTL8251A_WR_DATA_IO_BASE		0xFFF0
#define INTL8251A_STATUS_IO_BASE		0xFFF2
#define INTL8255A_CNTRL_IO_BASE			0xFFF2

void Init_8251A();

#endif /* __INTL8251_H__ */
