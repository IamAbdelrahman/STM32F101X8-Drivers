/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: LCD_Cfg.h
 *	@brief This module contains interface definitions for the
 *   LCD configuration.
 *****************************************************************************/

#ifndef CFG_LCD_CFG_H_
#define CFG_LCD_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../../MCAL/inc/GPIO.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
/*- LCD PORT */
#define LCD_DATA_PORT PORTA
#define LCD_COMMAND_PORT PORTA

/*- LCD CONTROL PINS */
#define RS 8
#define RW 9
#define EN 10

/*- LCD INSTRUCTION SET */
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

/*- LCD MODES */
#define DATA_SHIFT_8_MODE 0U
#define DATA_SHIFT_4_MODE 4U
#define EIGHT_BIT_MODE 1U
/* #define FOUR_BIT_MODE */

#define LCD_COMMAND                                                            \
  (ST_LCDCMD_t) {                                                              \
    LCD_COMMAND_PORT, {RS, RW, EN}, GPIO_OUTPUT_PUSHPULL,                      \
        GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ                                       \
  }
#define LCD_COMMAND_PINS 3

#ifdef EIGHT_BIT_MODE
#define LCD_DATA                                                               \
  (ST_LCDDATA_t) {                                                             \
    LCD_DATA_PORT, {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7},           \
        GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ                 \
  }
#define LCD_DATA_PINS 8
#endif

#ifdef FOURT_BIT_MODE
#define LCD_DATA                                                               \
  (ST_LCDDATA_t) {                                                             \
    LCD_DATA_PORT, {PIN4, PIN5, PIN6, PIN7}, GPIO_OUTPUT_PUSHPULL,             \
        GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ                                       \
  }
#define LCD_DATA_PINS 4
#endif

#define LCDCFG                                                                 \
  (ST_LCDConfig_t) { &LCD_COMMAND, &LCD_DATA }
/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
typedef struct {
  EN_GPIOX_t lcdPort;
  EN_GPIO_PIN_t lcdPin[3];
  EN_GPIO_PIN_STATE_t lcdState;
  EN_GPIO_OUT_MODE_SPEED_t lcdMode;
} ST_LCDCMD_t;

typedef struct {
  EN_GPIOX_t lcdPort;
  EN_GPIO_PIN_t lcdPin[8];
  EN_GPIO_PIN_STATE_t lcdState;
  EN_GPIO_OUT_MODE_SPEED_t lcdMode;
} ST_LCDDATA_t;

typedef struct {
  ST_LCDCMD_t *pLcdCmd;
  ST_LCDDATA_t *pLcdData;
} ST_LCDConfig_t;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: LCD_ConfigGet
 * Syntax: const ST_LCDConfig_t *const LCD_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the LCD based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_LCDConfig_t* const
 *************************************************************************/
const ST_LCDConfig_t *const LCD_ConfigGet(void);

#endif /* CFG_LCD_CFG_H_ */
