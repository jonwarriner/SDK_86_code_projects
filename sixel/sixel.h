#ifndef __SIXEL_H__
#define __SIXEL_H__

#include <stdio.h>
#include "types.h"

void setSixelMode();
void setTextMode();
void sixDrawLine(uint16_t st, uint16_t lp);

#endif /* __SIXEL_H__ */
