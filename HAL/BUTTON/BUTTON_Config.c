/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUTTON_Config.c
 * @brief This module contains the implementation for the BUTTON configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "BUTTON_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each BUTTON driver
 * Each row represents a single pin. Each column is representing a member of the
 * GpioConfig_t structure. This table is read in by BUTTON_Init(), where each
 * pin is then set up based on this table.
 */
const ST_BUTTON_t BUTTONConfig[] = {BUTTONPD2};

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : BUTTON_ConfigGet()
 *
 * This function is used to initialize the BUTTON based on the configuration
 * table defined in BUTTONConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_BUTTON_t *const BUTTON_ConfigGet(void) {
  return (ST_BUTTON_t *const) & BUTTONConfig[0];
}
