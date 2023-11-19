/*
 * common.h
 *
 *  Created on: Nov 18, 2023
 *      Author: zhiyuan
 */

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

//当前内部系统时钟频率（SYSCLK）
#define SYSTEMCLOCKS_PER_SEC 72000000

#include <stm32f1xx_hal.h>
#include <string>
#include <cstring>
#include <vector>
#include "usbd_cdc_if.h"

#ifdef __cplusplus
extern "C" {
#endif

void delaySecs(uint32_t s);
void delayMSecs(uint32_t ms);
void delayUSecs(uint32_t us);

#ifdef __cplusplus
}
#endif

class Log{
private:
//	static void sendStringViaCDC(const std::string& message);
public:
	static void sendStringViaCDC(const std::string& message);
	static std::vector<std::string> msgBuffer;
	static void addMsg(std::string msg);
	static void clrMsg(char flag);
	static void DisplayMsg();
};

#endif /* INC_COMMON_H_ */
