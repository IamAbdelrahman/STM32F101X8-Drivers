/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
* FILE DESCRIPTION
* ----------------------------------------------------------------------------
*	@file: SEG7_Cfg.h
*	@brief This module contains interface definitions for the
*   Seven Segment display configuration.
*****************************************************************************/

#ifndef CFG_SEG7_CFG_H_
#define CFG_SEG7_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../../MCAL/inc/GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define SEG_PINS 7

/*- DEFINE SEG7 COMMON CATHODE CONFIGURATION */
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

#define A 		0x77
#define B 		0x7C
#define C 		0x39
#define E 		0x79
#define F 		0x71
#define H 		0x76
#define L 		0x38
#define O 		0x3F
#define P 		0x73
#define S 		0x6D
#define U 		0x3E

#define SEGCFG                                                                 \
  (ST_SEG7Config_t) {      													   \
    PORTA, {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7} ,                  \
        GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ                 \
  }

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef struct {
  EN_GPIOX_t 			   segPort;
  EN_GPIO_PIN_t 		   segPins[8];
  EN_GPIO_PIN_STATE_t 	   segState;
  EN_GPIO_OUT_MODE_SPEED_t segMode;
} ST_SEG7Config_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/


/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
* Service Name: SEG7_ConfigGet
* Syntax: const ST_SEG7Config_t *const SEG7_ConfigGet(void)
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* @description: A helper function to initialize the SEG7 based on a config
* table.
* @param (in): None
* @param (inout): None
* @param (out): None
* @return: const ST_SEG7Config_t* const
*************************************************************************/
const ST_SEG7Config_t *const SEG7_ConfigGet(void);

#endif /* CFG_SEG7_CFG_H_ */
