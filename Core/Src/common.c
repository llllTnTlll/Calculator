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

void delayUS(uint32_t us){
	SysTick -> CTRL = 0;
	SysTick -> LOAD = us;
	SysTick -> VAL = 5;

}

#ifdef __cplusplus
}
#endif
