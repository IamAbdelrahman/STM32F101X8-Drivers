/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
* FILE DESCRIPTION
* ----------------------------------------------------------------------------
 * @file SEG7.c
 * @brief The implementation for the SEG7 driver
 *
****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../inc/SEG7.h"

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
extern vuint8_t configSizeSeg7;
extern TYPE volatile *const configLow[NUMBER_OF_PORTS];
extern TYPE volatile *const configHigh[NUMBER_OF_PORTS];
extern vuint8_t GetPosition(vuint8_t);
extern void ClearConfig(uint8_t, uint8_t, uint8_t);
/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/


/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void SEG7_Init(const ST_SEG7Config_t *pSEG77) {
  vuint8_t i = 0, j = 0, portNum = 0, pinNum = 0, pinCfg = 0;
  for (i = 0; i < configSizeSeg7; i++) {
    portNum = pSEG77->segPort % NUMBER_OF_PORTS;
    for (j = 0; j < SEG_PINS; j++) {
      pinNum = pSEG77->segPins[j] % NUMBER_OF_PINS_PER_PORT;
      vuint8_t Position = GetPosition(pinNum);
      ClearConfig(portNum, pinNum, Position);
      if (pSEG77->segState == GPIO_OUTPUT_PUSHPULL ||
          pSEG77->segState == GPIO_OUTPUT_OPENDRAIN ||
          pSEG77->segState == GPIO_ALTERNATE_PUSHPULL ||
          pSEG77->segState == GPIO_ALTERNATE_OPENDRAIN) {
        pinCfg = ((((pSEG77->segState - 4) << 2) | (pSEG77->segMode)) & 0x0f);
        if (pSEG77->segPins[j] < 8) {
          WRITE_2BITS(*(configLow[portNum]), pinCfg, Position);
        } else {
          WRITE_2BITS(*(configHigh[portNum]), pinCfg, Position);
        }
      }
    }
  }
}

void SEG7_Display(const ST_SEG7Config_t *pSEG7, vuint8_t Digit) {
	  switch (Digit) {
	  case 0:	GPIO_PortWrite(pSEG7->segPort, ZERO);
	    break;
	  case 1:	GPIO_PortWrite(pSEG7->segPort, ONE);
	    break;
	  case 2:	GPIO_PortWrite(pSEG7->segPort, TWO);
	    break;
	  case 3:	GPIO_PortWrite(pSEG7->segPort, THREE);
	    break;
	  case 4:	GPIO_PortWrite(pSEG7->segPort, FOUR);
	    break;
	  case 5:	GPIO_PortWrite(pSEG7->segPort, FIVE);
	    break;
	  case 6:	GPIO_PortWrite(pSEG7->segPort, SIX);
	    break;
	  case 7:	GPIO_PortWrite(pSEG7->segPort, SEVEN);
	    break;
	  case 8:	GPIO_PortWrite(pSEG7->segPort, EIGHT);
	    break;
	  case 9:	GPIO_PortWrite(pSEG7->segPort, NINE);
	    break;
	  case 'A':	GPIO_PortWrite(pSEG7->segPort, A);
	    break;
	  case 'B':	GPIO_PortWrite(pSEG7->segPort, B);
	    break;
	  case 'C':	GPIO_PortWrite(pSEG7->segPort, C);
	    break;
	  case 'E':	GPIO_PortWrite(pSEG7->segPort, E);
	    break;
	  case 'F':	GPIO_PortWrite(pSEG7->segPort, F);
	    break;
	  case 'H':	GPIO_PortWrite(pSEG7->segPort, H);
	    break;
	  case 'L':	GPIO_PortWrite(pSEG7->segPort, L);
	    break;
	  case 'O':	GPIO_PortWrite(pSEG7->segPort, O);
	    break;
	  case 'P':	GPIO_PortWrite(pSEG7->segPort, P);
	    break;
	  case 'S':	GPIO_PortWrite(pSEG7->segPort, S);
	    break;
	  case 'U':	GPIO_PortWrite(pSEG7->segPort, U);
	  default:	break;
  }
}

void SEG7_Clear(const ST_SEG7Config_t *pSEG7) {
	GPIO_PortWrite(pSEG7->segPort, 0X00);
}
