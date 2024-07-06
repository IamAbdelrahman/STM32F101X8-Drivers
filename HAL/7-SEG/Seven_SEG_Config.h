/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file SEG_Config.h
 * @brief This module contains interface definitions for the
 *  7-SEG configuration.
 * @author Abdelrahman Kamal
 *
 */

#ifndef SEG_CONFIG_H
#define SEG_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
/* Commands of 7-SEG Common Cathode */
#define ZERO 	0x3F
#define ONE 	0x05
#define TWO 	0x5B
#define THREE 	0x4F
#define FOUR 	0x66
#define FIVE 	0x6D
#define SIX 	0x7D
#define SEVEN 	0x07
#define EIGHT 	0x7F
#define NINE 	0x6F

#define A 	0x77
#define B 	0x7C
#define C 	0x39
#define E 	0x79
#define F 	0x71
#define H 	0x76
#define L 	0x38
#define O 	0x3F
#define P 	0x73
#define S 	0x6D
#define U 	0x3E

#define SEG0                                                                   \
  (ST_SEG_t) {                                                                 \
    PORTA, {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7},                   \
        GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ                 \
  }

/**********************************************************************
 * Typedefs
 **********************************************************************/
typedef struct {
  EN_GPIOX_t segPort;
  EN_GPIOPin_t segPins[8];
  EN_GPIOPinState_t segState;
  EN_GPIOOutModeSpeed_t segMode;
} ST_SEG_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_SEG_t *const SEG_ConfigGet(void);
#endif /** _SEG_H **/
