/*
 *  floor.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef FLOOR_H
#define FLOOR_H

/******************************************************************************/
/*                              DEFINE                                      */
/******************************************************************************/
#include "stdint.h"
/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void FLOOR_Init(void);
void FLOOR_SetPercent(uint8_t percent);
uint8_t FLOOR_GetPercent(void);
void FLOOR_ResetPercent(void);
#endif /*FLOOR_H*/