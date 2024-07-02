/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Seven_SEG_Config.h
 * @brief This module contains interface definitions for the
 *  7-SEG configuration.
 * @author Abdelrahman Kamal
 *
 */

#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define SEG_PORT PORTB
#define START_PIN PIN0
#define SEG_COMM_ANODE 1
// #define SEG_COMM_CATHODE	2
#ifdef SEG_COMM_ANODE
#define ZERO 0X40
#define ONE 0X79
#define TWO 0X24
#define THREE 0X30
#define FOUR 0X19
#define FIVE 0X12
#define SIX 0X02
#define SEVEN 0X78
#define EIGHT 0X00
#define NINE 0X10
#endif

#ifdef SEG_COMM_CATHODE
#define ZERO 63
#define ONE 5
#define TWO 91
#define THREE 79
#define FOUR 102
#define FIVE 109
#define SIX 125
#define SEVEN 7
#define EIGHT 127
#define NINE 111
#endif
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GpioConfig_t *const SEG_ConfigGet(void);

#endif /* SEVEN_SEG_CONFIG_H_ */
