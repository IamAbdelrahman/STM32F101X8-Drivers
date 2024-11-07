/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUZZER_Cfg.h
 *	@brief This module contains interface definitions for the
 *   BUZZER configuration.
 *****************************************************************************/

#ifndef CFG_BUZZER_CFG_H_
#define CFG_BUZZER_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../../MCAL/inc/GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- DEFINE BUZZER CONFIGURATION */
#define BUZZERPA0                                                              \
  (ST_BUZZERConfig_t) { &GPIOA0, HIGH }
#define BUZZERPB0                                                              \
  (ST_BUZZERConfig_t) { &GPIOB0, LOW }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  ST_GPIOConfig_t *buzzerCfg;
  EN_PIN_STATE_t buzzerState;
} ST_BUZZERConfig_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: BUZZER_ConfigGet
 * Syntax: const ST_BUZZERConfig_t *const BUZZER_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the BUZZER based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_BUZZERConfig_t* const
 *************************************************************************/
const ST_BUZZERConfig_t *const BUZZER_ConfigGet(void);

#endif /* BUZZER_CONFIG_H */
