/*
 * common.c
 *
 *  Created on: Nov 18, 2023
 *      Author: zhiyuan
 */

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

void delayUSecs(uint32_t us){
	SysTick->CTRL = 0;
	SysTick->LOAD = SYSTEMCLOCKS_PER_SEC / 1000000 * us - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while((SysTick->CTRL & 0x00010000) == 0);
	SysTick->CTRL = 0;
}

void delayMSecs(uint32_t ms){
	SysTick->CTRL = 0;
	SysTick->LOAD = SYSTEMCLOCKS_PER_SEC / 1000 * ms - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while((SysTick->CTRL & 0x00010000) == 0);
	SysTick->CTRL = 0;
}

void delaySecs(uint32_t s){
	SysTick->CTRL = 0;
	SysTick->LOAD = SYSTEMCLOCKS_PER_SEC * s - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	while((SysTick->CTRL & 0x00010000) == 0);
	SysTick->CTRL = 0;
}



#ifdef __cplusplus
}
#endif
