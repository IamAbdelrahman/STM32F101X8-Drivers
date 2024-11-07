/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: LED_Lcfg.c
 *	@brief This module contains the implementation for the LED configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../cfg/LED_Cfg.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
static const ST_LEDConfig_t configLed[] = {LEDPB0, LEDPB1};

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
vuint8_t configSizeLed = sizeof(configLed) / sizeof(configLed[0]);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
const ST_LEDConfig_t *const LED_ConfigGet(void) {
  return (ST_LEDConfig_t *const) & configLed[0];
}
