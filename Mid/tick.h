/*
 *  tick.h
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef TICK_H
#define TICK_H

/******************************************************************************/
/*                              DEFILE                                      */
/******************************************************************************/

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

void TICK_Init(void);
void TICK_Handle(void);
uint32_t GET_CurrentTick(void);
uint32_t GET_LengthTime(uint32_t currentTick);
uint8_t  GET_LengthTimeExceed(uint32_t startTime, uint32_t time_ms);
#endif /*TICK_H*/