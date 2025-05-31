/*
 * pressAndHold.h
 *
 *  Created on: May 31, 2025
 *      Author: Admin
 */

#ifndef INC_PRESSANDHOLD_H_
#define INC_PRESSANDHOLD_H_
#include "main.h"
#include "string.h"

#define minHoldTime 3000 // Minimum hold time in 0.1 milliseconds
#define MAX_MESSAGE_LENGTH 32 // Maximum length of messages
typedef struct
{
    GPIO_TypeDef* port; // GPIO port
    uint16_t pin;          // GPIO pin number
    char clickMes[MAX_MESSAGE_LENGTH]; // Message to send on click
    char holdMes[MAX_MESSAGE_LENGTH];  // Message to send on hold
    char releaseMes[MAX_MESSAGE_LENGTH]; // Message to send on release
    int holdTime;    // Time in 0.1 milliseconds to consider a press as a hold
    uint8_t isHolding;
} PressAndHold;

extern PressAndHold leftMouse; // Declare the left mouse button press and hold structure

void checkHold(PressAndHold* pah);

#endif /* INC_PRESSANDHOLD_H_ */
