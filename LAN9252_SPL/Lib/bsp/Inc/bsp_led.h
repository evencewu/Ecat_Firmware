#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include "stm32f4xx_conf.h"

void LedInit();

void LedWrite(uint8_t led);

#endif
