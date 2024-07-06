/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG.h
 * @brief The interface definition for the 7-segment Driver
 *
 * This is the header file for the definition of the interface for
 * the 7-segment driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef _SEG_H
#define _SEG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Seven_SEG_Config.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void SevenSeg_Init(ST_SEG_t *pSEG);
void SevenSeg_Display(ST_SEG_t *pSEG, vuint8_t display);
void SevenSeg_Clear(ST_SEG_t *pSEG);

#endif /* _SEG_H */
