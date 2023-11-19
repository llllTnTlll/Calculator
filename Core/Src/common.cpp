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

std::vector<std::string> Log::msgBuffer;

void Log::sendStringViaCDC(const std::string& message) {
    const char* cMessage = message.c_str();
    uint16_t len = strlen(cMessage);
    CDC_Transmit_FS((uint8_t*)cMessage, len);
}

void Log::addMsg(std::string msg){
	msgBuffer.push_back(msg);
}

void Log::clrMsg(char flag){
	if(flag == 'a')
		msgBuffer.clear();
}

void Log::DisplayMsg(){
	for (auto it = msgBuffer.begin(); it != msgBuffer.end(); ++it) {
		sendStringViaCDC(*it);
	}
}
