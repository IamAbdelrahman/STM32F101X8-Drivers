/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: LCD_Lcfg.c
 *	@brief This module contains the implementation for the LCD configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../cfg/LCD_Cfg.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL Datatypes
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
static const ST_LCDConfig_t configLcd[] = {LCDCFG};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint8_t configSizeLcd = sizeof(configLcd) / sizeof(configLcd[0]);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
const ST_LCDConfig_t *const LCD_ConfigGet(void) {
  return (ST_LCDConfig_t *const) & configLcd[0];
}
