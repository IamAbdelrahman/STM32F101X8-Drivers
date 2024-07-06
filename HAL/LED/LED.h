/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED.h
 * @brief The interface definition for the LCD driver
 *
 * This is the header file for the definition of the interface for
 * the LCD driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef LED_LED_H_
#define LED_LED_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "LED_Config.h"
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void LED_Init(ST_LED_t *pLED);
void LED_Control(ST_LED_t *pLED);

#endif /* LED_LED_H_ */
