/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.h
 * @brief The interface definition for the GPIO
 *
 * This is the header file for the definition of the interface for a GPIO
 * peripheral on a standard microcontroller.
 * @author Abdelrahman Kamal
 *
 */

#ifndef GPIO__H_
#define GPIO__H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO_Config.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define TYPE vuint32_t

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void Clock_Init();
void GPIO_Init(const ST_GPIOConfig_t *const Config);
PinState_t GPIO_PinRead(EN_GPIOX_t Port, EN_GPIOPin_t Pin);
void GPIO_PinWrite(EN_GPIOX_t Port, EN_GPIOPin_t Pin, PinState_t State);
void GPIO_PinToggle(EN_GPIOX_t Port, EN_GPIOPin_t Pin);
void GPIO_Reset(EN_GPIOX_t Port);
uint16_t GPIO_ReadPort(EN_GPIOX_t Port);
void GPIO_WritePort(EN_GPIOX_t Port, vuint16_t PortValue);
EN_GPIOLockState_t GPIO_LockPort(EN_GPIOX_t Port, EN_GPIOPin_t Pin);
/*
void GPIO_CallbackRegister(GPIOCallback_t Function,
                TYPE (*CallbackFunction)( type));
*/

#endif /** GPIO__H_ **/
/*** End of File ******************************************************/
