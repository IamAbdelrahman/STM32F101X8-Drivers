/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED.c
 * @brief The implementation for the LED driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "LED.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : LED_Init()
 *
 *  Description:
 *  This function is used to initialize a led connected to the MCU's
 *channel(pin)
 *
 *  PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *  @param pLED is the pointer to the configuration structure ST_LED_t
 *  @return void
 **********************************************************************/
void LED_Init(ST_LED_t *pLED) { GPIO_Init(&pLED->ledCfg); }

/**********************************************************************
 * Function : LED_Control()
 *
 *  Description:
 *  This function is used to control a led connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: LED is initialized
 *  @param pLED is the pointer to the configuration structure ST_LED_t

 *  @return void
 **********************************************************************/
void LED_Control(ST_LED_t *pLED) {
  switch (pLED->ledState) {
  case HIGH:
    GPIO_PinWrite(pLED->ledCfg.Port, pLED->ledCfg.Pin, HIGH);
    break;
  case LOW:
    GPIO_PinWrite(pLED->ledCfg.Port, pLED->ledCfg.Pin, LOW);
    break;
  case TOGGLE:
    GPIO_PinToggle(pLED->ledCfg.Port, pLED->ledCfg.Pin);
    break;
  default:
    break;
  }
}
