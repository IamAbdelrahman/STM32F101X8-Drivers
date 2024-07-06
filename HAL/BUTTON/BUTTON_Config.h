/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUTTON_Config.h
 * @brief This module contains interface definitions for the
 *  BUTTON configuration.
 * @author Abdelrahman Kamal
 *
 */

#ifndef BUTTON_CONFIG_H
#define BUTTON_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"
/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define BUTTONPD2                                                              \
  (ST_BUTTON_t) {                                                              \
    { PORTD, PIN2, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED }  \
  }

/**********************************************************************
 * Typedefs
 **********************************************************************/
typedef struct {
  ST_GPIOConfig_t buttonCfg;
  PinState_t buttonState;
} ST_BUTTON_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_BUTTON_t *const BUTTON_ConfigGet(void);

#endif /* BUTTON_CONFIG_H_ */
