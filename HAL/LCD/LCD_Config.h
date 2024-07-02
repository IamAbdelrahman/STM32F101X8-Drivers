/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LCD_Config.h
 * @brief This module contains interface definitions for the
 *  LCD configuration.
 * @author Abdelrahman Kamal
 *
 */

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/

#define LCD_DATA_PORT PORTA
#define LCD_COMMAND_PORT PORTA
/** LCD Control/Command Pins **/
#define RS 8
#define RW 9
#define EN 10

/** LCD Modes **/
#define DATA_SHIFT_8_MODE 0
#define DATA_SHIFT_4_MODE 4
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

/** LCD Instruction Set **/
#define LCD_FUNCTION_8BIT_2LINES (0x38)
#define LCD_FUNCTION_8BIT_1LINES (0x30)
#define LCD_FUNCTION_4BIT_2LINES (0x28)
#define LCD_FUNCTION_4BIT_1LINES (0x20)
#define LCD_MOVE_DISP_RIGHT (0x1C)
#define LCD_MOVE_DISP_LEFT (0x18)
#define LCD_MOVE_CURSOR_RIGHT (0x14)
#define LCD_MOVE_CURSOR_LEFT (0x10)
#define LCD_DISP_OFF (0x08)
#define LCD_DISP_ON_CURSOR (0x0E)
#define LCD_DISP_ON_CURSOR_BLINK (0x0F)
#define LCD_DISP_ON_BLINK (0x0D)
#define LCD_DISP_ON (0x0C)
#define LCD_ENTRY_DEC (0x04)
#define LCD_ENTRY_DEC_SHIFT (0x05)
#define LCD_ENTRY_INC_ (0x06)
#define LCD_ENTRY_INC_SHIFT (0x07)
#define LCD_BEGIN_AT_FIRST_ROW (0x80)
#define LCD_BEGIN_AT_SECOND_ROW (0xC0)
#define LCD_CLEAR_SCREEN (0x01)

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GpioConfig_t *const LCD_ConfigGet(void);

#endif /* LCD_CONFIG_H */
