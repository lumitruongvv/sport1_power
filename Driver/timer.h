/*
 *  time.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#ifndef _TIMER_H_
#define _TIMER_H_

/******************************************************************************/
/*                              DEFILE                                      */
/******************************************************************************/

typedef void (*type_TimerCallBackFnc)(void);

enum
{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3
};

enum
{
    TIME_DISABLE,
    TIME_ENABLE
};


/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
void TIMER_Init(uint8_t channel);
void TIMER_CallBackInit(type_TimerCallBackFnc pHandle);
void TIMER_Enable(uint8_t channel);
void TIMER_Disable(uint8_t channel);

#endif /*_TIMER_H_*/
