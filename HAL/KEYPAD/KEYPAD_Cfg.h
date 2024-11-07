/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: KEYPAD_Cfg.h
 *	@brief This module contains interface definitions for the
 *   KEYPAD configuration.
 *****************************************************************************/

#ifndef CFG_KEYPAD_CFG_H_
#define CFG_KEYPAD_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../../MCAL/inc/GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define KEYPAD_PORT PORTB
#define ROWS 4
#define COLS 4
#define ROW0 0
#define ROW1 1
#define ROW2 2
#define ROW3 3
#define COL0 4
#define COL1 5
#define COL2 6
#define COL3 7

#define KEYROWS                                                                \
  { GPIOB0, GPIOB1, GPIOB2, GPIOB3 }
#define KEYCOLS                                                                \
  { GPIOB4, GPIOB5, GPIOB6, GPIOB7 }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  ST_GPIOConfig_t keyRowCfg[4];
  ST_GPIOConfig_t keyColCfg[4];
} ST_KEYPADConfig_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: KEYPAD_ConfigGet
 * Syntax: const ST_KEYPADConfig_t *const KEYPAD_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the KEYPAD based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_KEYPADConfig_t* const
 *************************************************************************/
const ST_KEYPADConfig_t *const KEYPAD_ConfigGet(void);

#endif /* CFG_KEYPAD_CFG_H_ */
