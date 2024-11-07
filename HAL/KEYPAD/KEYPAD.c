/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * @file KEYPAD.c
 * @brief The implementation for the KEYPAD driver
 *
 ****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../inc/KEYPAD.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/

/*- LOCAL DATATYPES
 -----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void KEYPAD_Init(ST_KEYPADConfig_t *pKEYPAD) {
  GPIO_Init(pKEYPAD->keyRowCfg);
  GPIO_Init(pKEYPAD->keyColCfg);
  vuint8_t i = 0;
  for (i = 0; i < ROWS; i++) {
    GPIO_PinWrite(KEYPAD_PORT, pKEYPAD->keyRowCfg[i].pinNumber, LOW);
  }
}

vuint8_t KEYPAD_getKey(ST_KEYPADConfig_t *pKEYPAD) {
  vuint8_t i = 0, j = 0;
  for (i = 0; i < ROWS; i++) {
    GPIO_PinWrite(KEYPAD_PORT, pKEYPAD->keyRowCfg[i].pinNumber, HIGH);
    for (j = 0; j < COLS; j++) {
      if (GPIO_PinRead(KEYPAD_PORT, pKEYPAD->keyColCfg[j].pinNumber)) {
        while (GPIO_PinRead(KEYPAD_PORT, pKEYPAD->keyColCfg[j].pinNumber))
          ;
        GPIO_PinWrite(KEYPAD_PORT, pKEYPAD->keyRowCfg[i].pinNumber, LOW);
        switch (i) {
        case 0:
          if (j == 0)
            return '7';
          if (j == 1)
            return '8';
          if (j == 2)
            return '9';
          if (j == 3)
            return '/';
          break;
        case 1:
          if (j == 0)
            return '4';
          if (j == 1)
            return '5';
          if (j == 2)
            return '6';
          if (j == 3)
            return '*';
          break;
        case 2:
          if (j == 0)
            return '1';
          if (j == 1)
            return '2';
          if (j == 2)
            return '3';
          if (j == 3)
            return '-';
          break;
        case 3:
          if (j == 0)
            return '!';
          if (j == 1)
            return '0';
          if (j == 2)
            return '=';
          if (j == 3)
            return '+';
          break;
        }
      }
    }
    GPIO_PinWrite(KEYPAD_PORT, pKEYPAD->keyRowCfg[i].pinNumber, LOW);
  }
  return 'N'; // No key pressed
}
