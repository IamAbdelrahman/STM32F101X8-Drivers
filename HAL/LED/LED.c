/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file LED.c
 * @brief The implementation for the LED driver
 *
 ****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../inc/LED.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint8_t configSizeLed;

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void LED_Init(const ST_LEDConfig_t *pLEDArray) {
  vuint8_t i = 0;
  for (i = 0; i < configSizeLed; i++) {
    GPIO_Init(pLEDArray[i].ledCfg);
  }
}

void LED_Control(const ST_LEDConfig_t *pLED) {
  switch (pLED->ledState) {
  case HIGH:
    GPIO_PinWrite(pLED->ledCfg->portNumber, pLED->ledCfg->pinNumber, HIGH);
    break;
  case LOW:
    GPIO_PinWrite(pLED->ledCfg->portNumber, pLED->ledCfg->pinNumber, LOW);
    break;
  case TOGGLE:
    GPIO_PinToggle(pLED->ledCfg->portNumber, pLED->ledCfg->pinNumber);
    break;
  default:
    // Handle undefined states if necessary
    break;
  }
}
