/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG_Config.c
 * @brief This module contains the implementation for the 7-SEG configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Seven_SEG_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each 7-SEG driver
 * Each row represents a single pin. Each column is representing a member of the
 * GpioConfig_t structure. This table is read in by 7-SEG_Init(), where each pin
 * is then set up based on this table.
 */
const ST_SEG_t SEGConfig[] = {SEG0};

vuint8_t SEG_CfgSize = sizeof(SEGConfig) / sizeof(SEGConfig[0]);

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : 7-SEG_ConfigGet()
 *
 * This function is used to initialize the 7-SEG based on the configuration
 * table defined in 7-SEGConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_SEG_t *const SEG_ConfigGet(void) {
  return (ST_SEG_t *const) & SEGConfig[0];
}
