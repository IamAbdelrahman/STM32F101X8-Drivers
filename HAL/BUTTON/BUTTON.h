/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUTTON.h
 * @brief The interface definition for the BUTTON Driver
 *
 * This is the header file for the definition of the interface for
 * the BUTTON driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef BUTTON_BUTTON_H_
#define BUTTON_BUTTON_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "BUTTON_Config.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void BUTTON_Init(ST_BUTTON_t *pBUTTON);
PinState_t BUTTON_Read(ST_BUTTON_t *pBUTTON);

#endif /* BUTTON_BUTTON_H_ */
