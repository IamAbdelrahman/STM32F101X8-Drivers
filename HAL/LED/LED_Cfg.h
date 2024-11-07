/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: LED_Cfg.h
 *	@brief This module contains interface definitions for the
 *   LED configuration.
 *****************************************************************************/

#ifndef CFG_LED_CFG_H_
#define CFG_LED_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../../MCAL/inc/GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- DEFINE LED CONFIGURATION */
#define LEDPB0                                                                 \
  (ST_LEDConfig_t) { &GPIOB0, HIGH }
#define LEDPB1                                                                 \
  (ST_LEDConfig_t) { &GPIOB1, TOGGLE }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  ST_GPIOConfig_t *ledCfg;
  EN_PIN_STATE_t ledState;
} ST_LEDConfig_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: LED_ConfigGet
 * Syntax: const ST_LEDConfig_t *const LED_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the LED based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_LEDConfig_t* const
 *************************************************************************/
const ST_LEDConfig_t *const LED_ConfigGet(void);

#endif /* CFG_LED_CFG_H_ */
