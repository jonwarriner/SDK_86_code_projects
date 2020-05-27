#ifndef __MSDELAY_H__
#define __MSDELAY_H__

#include "types.h"

#define LOOP_CNT	21.0L				/* number of clock cycles per msDelay loop iteration */

/* This macro caclulates the number of required msDelay loop iterations */
/* required to acheive the desired delay in ms.  It then calls the      */
/* msDelay assembly function.  											*/
#define DELAY_MS(x)		(msDelay((uint16_t)((x * F_CLK * 1000.0L) / LOOP_CNT)))

void msDelay(uint16_t cnt);

#endif /* __MSDELAY_H__ */
