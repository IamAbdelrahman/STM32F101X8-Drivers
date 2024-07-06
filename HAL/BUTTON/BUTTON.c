/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUTTON.c
 * @brief The implementation for the BUTTON driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "BUTTON.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : BUTTON_Init()
 *
 *  Description:
 *  This function is used to initialize a button connected to the MCU's
 *channel(pin)
 *
 *  PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *  @param pBUTTON is the pointer to the configuration structure ST_BUTTON_t
 *  @return void
 **********************************************************************/
void BUTTON_Init(ST_BUTTON_t *pBUTTON) { GPIO_Init(&pBUTTON->buttonCfg); }

/**********************************************************************
 * Function : BUTTON_Control()
 *
 *  Description:
 *  This function is used to read a button's state connected to the MCU's
 channel(pin)
 *
 *  PRE-CONDITION: BUTTON is initialized
 *  @param pBUTTON is the pointer to the configuration structure ST_BUTTON_t

 *  @return void
 **********************************************************************/
PinState_t BUTTON_Read(ST_BUTTON_t *pBUTTON) {
  pBUTTON->buttonState =
      GPIO_PinRead(pBUTTON->buttonCfg.Port, pBUTTON->buttonCfg.Pin);
  return (pBUTTON->buttonState);
}
