/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file LCD.c
 * @brief The implementation for the LCD driver
 *
 ****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../inc/LCD.h"
#include <stdio.h>

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
 -----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void Delay(vuint32_t);
void LCD_CmdCfg(ST_LCDConfig_t *);
void LCD_DataCfg(ST_LCDConfig_t *);
void LCD_Config(ST_LCDConfig_t *);
/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE ARRAY OF BITMAPS OF SHAPES */
static vuint8_t Bell[8] = {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00};
/* TODO
 * HEART, SPEAKER, SMILE, AND MUSIC
 */

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint8_t configSizeLcd;
extern TYPE volatile *const dataOut[NUMBER_OF_PORTS];
extern TYPE volatile *const configLow[NUMBER_OF_PORTS];
extern TYPE volatile *const configHigh[NUMBER_OF_PORTS];
vuint16_t count_char = 0;

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
void Delay(vuint32_t Time) {
  uint32_t i, j;
  for (i = 0; i < Time; i++)
    for (j = 0; j < 255; j++)
      ;
}

void LCD_XY(vuint8_t Line, vuint8_t Pos) {
  if (Line == 1) {
    if (Pos < 16 && Pos >= 0) {
      LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW + Pos);
    }
  }
  if (Line == 2) {
    if (Pos < 16 && Pos >= 0) {
      LCD_SendCmd(LCD_BEGIN_AT_SECOND_ROW + Pos);
    }
  }
}

void SetCursor(vuint8_t Counter) {
  if (Counter == 16) {
    LCD_XY(2, 0);
  } else if (Counter == 32) {
    LCD_ClearScreen();
    LCD_XY(1, 0);
    Counter = 0;
  }
}

void LCD_CmdCfg(ST_LCDConfig_t *pLcd) {
  vuint8_t i = 0, j = 0, portNum = 0, pinNum = 0, pinCfg = 0;
  for (i = 0; i < configSizeLcd; i++) {
    portNum = pLcd->pLcdCmd->lcdPort % NUMBER_OF_PORTS;
    for (j = 0; j < LCD_COMMAND_PINS; j++) {
      pinNum = pLcd->pLcdCmd->lcdPin[j] % NUMBER_OF_PINS_PER_PORT;
      vuint8_t Position = GetPosition(pinNum);
      ClearConfig(portNum, pinNum, Position);
      if (pLcd->pLcdCmd->lcdState == GPIO_OUTPUT_PUSHPULL ||
          pLcd->pLcdCmd->lcdState == GPIO_OUTPUT_OPENDRAIN ||
          pLcd->pLcdCmd->lcdState == GPIO_ALTERNATE_PUSHPULL ||
          pLcd->pLcdCmd->lcdState == GPIO_ALTERNATE_OPENDRAIN) {
        pinCfg =
            ((((pLcd->pLcdCmd->lcdState - 4) << 2) | (pLcd->pLcdCmd->lcdMode)) &
             0x0f);
        if (pLcd->pLcdCmd->lcdPin[j] < 8) {
          WRITE_2BITS(*(configLow[portNum]), pinCfg, Position);
        } else {
          WRITE_2BITS(*(configHigh[portNum]), pinCfg, Position);
        }
      }
    }
  }
}

void LCD_DataCfg(ST_LCDConfig_t *pLcd) {
  vuint8_t i = 0, j = 0, portNum = 0, pinNum = 0, pinCfg = 0;
  for (i = 0; i < configSizeLcd; i++) {
    portNum = pLcd->pLcdData->lcdPort % NUMBER_OF_PORTS;
    for (j = 0; j < LCD_DATA_PINS; j++) {
      pinNum = pLcd->pLcdData->lcdPin[j] % NUMBER_OF_PINS_PER_PORT;
      vuint8_t Position = GetPosition(pinNum);
      ClearConfig(portNum, pinNum, Position);
      if (pLcd->pLcdData->lcdState == GPIO_OUTPUT_PUSHPULL ||
          pLcd->pLcdData->lcdState == GPIO_OUTPUT_OPENDRAIN ||
          pLcd->pLcdData->lcdState == GPIO_ALTERNATE_PUSHPULL ||
          pLcd->pLcdData->lcdState == GPIO_ALTERNATE_OPENDRAIN) {
        pinCfg = ((((pLcd->pLcdData->lcdState - 4) << 2) |
                   (pLcd->pLcdData->lcdMode)) &
                  0x0f);
        if (pLcd->pLcdData->lcdPin[j] < 8) {
          WRITE_2BITS(*(configLow[portNum]), pinCfg, Position);
        } else {
          WRITE_2BITS(*(configHigh[portNum]), pinCfg, Position);
        }
      }
    }
  }
}

void LCD_Config(ST_LCDConfig_t *pLcd) {
  LCD_CmdCfg(pLcd);
  LCD_DataCfg(pLcd);
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void LCD_Kick() {
  GPIO_PinWrite(LCD_COMMAND_PORT, EN, HIGH);
  Delay(50);
  GPIO_PinWrite(LCD_COMMAND_PORT, EN, LOW);
  Delay(50);
}

void LCD_Init(ST_LCDConfig_t *pLcd) {
  Delay(20);
  LCD_Config(pLcd);
  Delay(20);
#ifdef EIGHT_BIT_MODE
  LCD_SendCmd(LCD_FUNCTION_8BIT_2LINES);
  LCD_SendCmd(LCD_DISP_ON_CURSOR);
  LCD_SendCmd(LCD_ENTRY_INC_);
  LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW);
  LCD_ClearScreen();
#endif

#ifdef FOUR_BIT_MODE
  LCD_SendCmd(0x02);
  LCD_SendCmd(LCD_FUNCTION_4BIT_2LINES);
  LCD_SendCmd(LCD_DISP_ON_CURSOR);
  LCD_SendCmd(LCD_ENTRY_INC_);
  LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW);
  LCD_ClearScreen();
#endif
}

void LCD_SendCmd(vuint8_t cmd) {
  GPIO_PinWrite(LCD_COMMAND_PORT, RS, LOW);
  GPIO_PinWrite(LCD_COMMAND_PORT, RW, LOW);
#ifdef EIGHT_BIT_MODE
  *(dataOut[LCD_DATA_PORT]) = (*(dataOut[LCD_DATA_PORT]) & 0xFF00) | cmd;
  Delay(1);
  LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
  /** Sending the upper nibble **/
  *(dataOut[LCD_DATA_PORT]) =
      (*(dataOut[LCD_DATA_PORT]) & 0xFF0F) | (cmd & 0xF0);
  Delay(10);
  LCD_Kick();
  /** Sending the lower nibble **/
  *(dataOut[LCD_DATA_PORT]) = (*(dataOut[LCD_DATA_PORT]) & 0xFF0F) | (cmd << 4);
  Delay(10);
  LCD_Kick();
#endif
}

void LCD_WriteChar(vuint8_t chr) {
  GPIO_PinWrite(LCD_COMMAND_PORT, RS, HIGH);
  GPIO_PinWrite(LCD_COMMAND_PORT, RW, LOW);
#ifdef EIGHT_BIT_MODE
  *(dataOut[LCD_DATA_PORT]) = (*(dataOut[LCD_DATA_PORT]) & 0xFF00) | chr;
  Delay(1);
  LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
  /** Sending the upper nibble **/
  *(dataOut[LCD_DATA_PORT]) =
      (*(dataOut[LCD_DATA_PORT]) & 0xFF0F) | (chr & 0xF0);
  Delay(10);
  LCD_Kick();
  /** Sending the lower nibble **/
  *(dataOut[LCD_DATA_PORT]) = (*(dataOut[LCD_DATA_PORT]) & 0xFF0F) | (chr << 4);
  Delay(10);
  LCD_Kick();
  count_char++;
#endif
}

void LCD_WriteString(vuint8_t *Str) {
  vuint16_t i = 0, count = 0;
  for (i = 0; Str[i] != 0; i++) {
    LCD_WriteChar(Str[i]);
    count++;
    SetCursor(count);
  }
}

void LCD_ClearScreen() { LCD_SendCmd(LCD_CLEAR_SCREEN); }

void LCD_CreateShape(EN_Shapes_t Shape, vuint8_t Location) {
  vuint8_t *Pattern;
  switch (Shape) {
  case BELL:
    Pattern = Bell;
    break;
  default:
    break;
  }
  vuint8_t i = 0;
  LCD_SendCmd(0x40 + (Location * 8)); /** Send the address of CGRAM **/
  for (i = 0; i < 8; i++) {
    LCD_WriteChar(Pattern[i]); /** Pass the bytes of Pattern on LCD **/
  }
  LCD_SendCmd(LCD_BEGIN_AT_FIRST_ROW);
  LCD_WriteChar(0);
  Delay(1);
}

void LCD_WriteInt(vint32_t Num) {
  vint8_t Size = 0, i;
  vuint8_t Str[10];
  if (Num > 0) {
    while (Num != 0) {
      Str[Size++] = Num % 10;
      Num /= 10;
    }
    for (i = Size - 1; i >= 0; i--)
      LCD_WriteChar(Str[i] + 48);
  } else if (Num < 0) {
    Num *= -1;
    while (Num != 0) {
      Str[Size++] = Num % 10;
      Num /= 10;
    }
    LCD_WriteChar('-');
    for (i = Size - 1; i >= 0; i--)
      LCD_WriteChar(Str[i] + 48);
  } else {
    LCD_WriteChar(48);
  }
}

void LCD_WriteFloat(float realNum) {
  float floatPart = realNum - (vint32_t)realNum;
  vint32_t intPart = realNum - floatPart;
  LCD_WriteInt(intPart);
  LCD_WriteChar('.');
  LCD_WriteInt(floatPart * 10000);
}
