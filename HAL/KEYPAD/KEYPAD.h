/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file KEYPAD.h
 * @brief The interface definition for the KEYPAD driver
 * @description This is the header file for the definition of the interface
 * for the KEYPAD driver connected to the MCU.
 *****************************************************************************/
#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../cfg/KEYPAD_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: KEYPAD_Init
 * Syntax: void KEYPAD_Init(ST_KEYPADConfig_t *pKEYPAD)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize KEYPAD
 * @param (in): pKEYPAD a pointer to the KEYPADConfig structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void KEYPAD_Init(ST_KEYPADConfig_t *pKEYPAD);

/************************************************************************
 * Service Name: KEYPAD_getKey
 * Syntax: vuint8_t KEYPAD_getKey();
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Control KEYPAD using the key-detection algorithm
 * @param (in): pKEYPAD a pointer to the KEYPADConfig structure
 * @param (inout): None
 * @param (out): None
 * @return: vuint8_t as a pressed key
 *************************************************************************/
vuint8_t KEYPAD_getKey();

#endif /* INC_KEYPAD_H_ */
