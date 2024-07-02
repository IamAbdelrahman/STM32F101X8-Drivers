/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Seven_SEG.h
 * @brief The interface definition for the 7-segment Driver
 *
 * This is the header file for the definition of the interface for
 * the 7-segment driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Seven_SEG_Config.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void SevenSegment_Init();
void SevenSegment_DisplayDigit(vuint8_t digit);
void SevenSegment_Clear();

#endif /* SEVEN_SEG_H_ */
