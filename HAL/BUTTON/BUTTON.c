/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUTTON.c
 * 	@brief The implementation for the BUTTON driver
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../inc/BUTTON.h"

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
extern vuint8_t configSizeButton;

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void BUTTON_Init(ST_BUTTONConfig_t *pBUTTON) {
  vuint8_t i = 0;
  for (i = 0; i < configSizeButton; i++)
    GPIO_Init(pBUTTON[i].buttonCfg);
}

EN_PIN_STATE_t BUTTON_Read(ST_BUTTONConfig_t *pBUTTON) {
  pBUTTON->buttonState = GPIO_PinRead(pBUTTON->buttonCfg->portNumber,
                         pBUTTON->buttonCfg->pinNumber);
  return (pBUTTON->buttonState);
}
