/*
 * common.h
 *
 *  Created on: Nov 18, 2023
 *      Author: zhiyuan
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include <stm32f1xx_hal.h>

#ifdef __cplusplus
extern "C" {
#endif

void delayS(uint32_t s);
void delayMS(uint32_t ms);
void delayUS(uint32_t us);

#ifdef __cplusplus
}
#endif

#endif /* INC_COMMON_H_ */
