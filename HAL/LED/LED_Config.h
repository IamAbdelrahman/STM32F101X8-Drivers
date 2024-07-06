/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED_Config.h
 * @brief This module contains interface definitions for the
 *  LED configuration.
 * @author Abdelrahman Kamal
 *
 */

#ifndef LED_CONFIG_H
#define LED_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define LEDPC0                                                                 \
  (ST_LED_t) {                                                                 \
    {PORTC, PIN0, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},     \
        HIGH                                                                   \
  }
#define LEDPC1                                                                 \
  (ST_LED_t) {                                                                 \
    {PORTC, PIN1, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},     \
        TOGGLE                                                                 \
  }

/**********************************************************************
 * Typedefs
 **********************************************************************/
typedef struct {
  ST_GPIOConfig_t ledCfg;
  PinState_t ledState;
} ST_LED_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_LED_t *const LED_ConfigGet(void);

#endif /* LED_CONFIG_H_ */
