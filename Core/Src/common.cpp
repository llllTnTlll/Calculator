/*
 * common.c
 *
 *  Created on: Nov 18, 2023
 *      Author: zhiyuan
 */

#include <common.hpp>

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

void keepUSBVisable(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	/* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOA_CLK_ENABLE();
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
	/*Configure GPIO pin : PA12 */
	GPIO_InitStruct.Pin = GPIO_PIN_12;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
	HAL_Delay(65);
	//先把PA12拉低再拉高，利用D+模拟USB的拔插动作
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
	HAL_Delay(65);
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
