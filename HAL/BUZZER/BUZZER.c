/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file BUZZER.c
 * @brief The implementation for the BUZZER driver
 *
 ****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../inc/BUZZER.h"

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
extern vuint8_t configSizeBuzzer;

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void BUZZER_Init(ST_BUZZERConfig_t *pBUZZER) {
  vuint8_t i = 0;
  for (i = 0; i < configSizeBuzzer; i++)
    GPIO_Init(pBUZZER[i].buzzerCfg);
}

void BUZZER_Control(ST_BUZZERConfig_t *pBUZZER) {
  switch (pBUZZER->buzzerState) {
  case HIGH:
    GPIO_PinWrite(pBUZZER->buzzerCfg->portNumber, pBUZZER->buzzerCfg->pinNumber,
                  HIGH);
    break;
  case LOW:
    GPIO_PinWrite(pBUZZER->buzzerCfg->portNumber, pBUZZER->buzzerCfg->pinNumber,
                  LOW);
    break;
  case TOGGLE:
    GPIO_PinToggle(pBUZZER->buzzerCfg->portNumber,
                   pBUZZER->buzzerCfg->pinNumber);
    break;
  default:
    break;
  }
}
