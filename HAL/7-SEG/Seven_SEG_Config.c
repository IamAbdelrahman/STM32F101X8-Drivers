/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Seven_SEG_Config.c
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
const ST_GpioConfig_t SEGConfig[] = {
    /*   PORT            	PIN					STATE					MODE
     */
    {SEG_PORT, PIN0, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {SEG_PORT, PIN1, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {SEG_PORT, PIN2, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {SEG_PORT, PIN3, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {SEG_PORT, PIN4, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {SEG_PORT, PIN5, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {SEG_PORT, PIN6, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ}};

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
const ST_GpioConfig_t *const SEG_ConfigGet(void) {
  return (ST_GpioConfig_t *const) & SEGConfig[0];
}
