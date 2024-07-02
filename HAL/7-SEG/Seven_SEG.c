/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG.c
 * @brief The implementation for the 7-SEG driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Seven_SEG.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : SevenSegment_Init()
 *
 *  Description:
 *  This function is used to initialize a 7-segment connected to the MCU's
 channel(pin)
 *
 *  PRE-CONDITION: Configuration table needs to populated (sizeof > 0)

 *  @return void
 **********************************************************************/
void SevenSegment_Init() { Gpio_Init(SEG_ConfigGet()); }

/**********************************************************************
 * Function : SevenSegment_DisplayDigit()
 *
 *  Description:
 *  This function is used to display a digit on
 *  a 7-segment connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as Gpio
 *  PRE-CONDITION: The channel is within the maximum GpioPin_t definition

 *  @param Port is the port of the pin to write using the EN_GpioX_t enum
 definition
 *  @param digit is the input digit by the user to be displayed from
 (0:START_PIN)

 *  @return void
 **********************************************************************/
void SevenSegment_DisplayDigit(vuint8_t digit) {
  switch (digit) {
  case 0:
    Gpio_WritePort(SEG_PORT, (ZERO << START_PIN));
    break;
  case 1:
    Gpio_WritePort(SEG_PORT, (ONE << START_PIN));
    break;
  case 2:
    Gpio_WritePort(SEG_PORT, (TWO << START_PIN));
    break;
  case 3:
    Gpio_WritePort(SEG_PORT, (THREE << START_PIN));
    break;
  case 4:
    Gpio_WritePort(SEG_PORT, (FOUR << START_PIN));
    break;
  case 5:
    Gpio_WritePort(SEG_PORT, (FIVE << START_PIN));
    break;
  case 6:
    Gpio_WritePort(SEG_PORT, (SIX << START_PIN));
    break;
  case 7:
    Gpio_WritePort(SEG_PORT, (SEVEN << START_PIN));
    break;
  case 8:
    Gpio_WritePort(SEG_PORT, (EIGHT << START_PIN));
    break;
  case 9:
    Gpio_WritePort(SEG_PORT, (NINE << START_PIN));
    break;
  default:
    break;
  }
}

/**********************************************************************
 * Function : SevenSegment_Clear()
 *
 *  Description:
 *  This function is used to clear
 *  a 7-segment connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as Gpio
 *  PRE-CONDITION: The channel is within the maximum GpioPin_t definition

 *  @param Port is the port of the pin to write using the EN_GpioX_t enum
 definition
 *  @return void
 **********************************************************************/
void SevenSegment_Clear() { Gpio_WritePort(SEG_PORT, 0); }
