/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: BUZZER_Lcfg.c
 *	@brief This module contains the implementation for the BUZZER
 *configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../cfg/BUZZER_Cfg.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
static const ST_BUZZERConfig_t configBuzzer[] = {BUZZERPA0, BUZZERPB0};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint8_t configSizeBuzzer = sizeof(configBuzzer) / sizeof(configBuzzer[0]);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
const ST_BUZZERConfig_t *const BUZZER_ConfigGet(void) {
  return (ST_BUZZERConfig_t *const) & configBuzzer[0];
}
