/*
 * pressAndHold.c
 *
 *  Created on: May 31, 2025
 *      Author: Admin
 */
#include "pressAndHold.h"
#include "string.h"
PressAndHold leftMouse = {
    .port = GPIOA,
    .pin = GPIO_PIN_0,
    .clickMes = "LMClick",
    .holdMes = "LMHold",
    .releaseMes = "LMRel",
    .holdTime = -1,  // Start with -1 to indicate no hold time
    .isHolding = 0
};

extern UART_HandleTypeDef huart1;
void checkHold(PressAndHold* pah){
    if (HAL_GPIO_ReadPin(pah->port, pah->pin) == GPIO_PIN_SET) {
        if (!pah->isHolding && pah->holdTime >= minHoldTime) {
            pah->isHolding = 1;
            HAL_UART_Transmit(&huart1, (uint8_t*)pah->holdMes, strlen(pah->holdMes), 10);
            HAL_Delay(1);
        } 
    }       
}


