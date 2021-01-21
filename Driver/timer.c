/*
 *  time.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "timer.h"

/******************************************************************************/
/*                              DECLARE AND DEFINE                                      */
/******************************************************************************/

type_TimerCallBackFnc p_timerCallBack;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void TIMER_Init(uint8_t channel)
{
    switch (channel)
    {
    case TIMER0:
        CKCON |= (1 << 3); // clock source of Timer 0 is direct the system clock
        TL0 =  0x80;  // 1ms
        TH0 =  0xC1;  // 1ms
        TMOD |= (1 << 0); // timer0 16bit
        break;
    case TIMER1:
        break;
    case TIMER2:
        break;
    case TIMER3:
        break;
    default:
        break;
    }
    TIMER_Disable(TIMER0);
}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void TIMER_CallBackInit(type_TimerCallBackFnc pHandle)
{
    p_timerCallBack = pHandle;
}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void TIMER_Enable(uint8_t channel)
{
    switch (channel)
    {
    case TIMER0:
        TCON  |= (1 << 4); // enable timer0
        break;
    case TIMER1:
        TCON  |= (1 << 6); // enable timer1
    case TIMER2:
        T2CON |= (1 << 2); // enable time2
    case TIMER3:
        T3CON |= (1 << 3); // enable time3
    default:
        break;
    }
}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void TIMER_Disable(uint8_t channel)
{
    switch (channel)
    {
    case TIMER0:
        TCON  &= ~(1 << 4); // enable timer0
        break;
    case TIMER1:
        TCON  &= ~(1 << 6); // enable timer1
    case TIMER2:
        T2CON &= ~(1 << 2); // enable time2
    case TIMER3:
        T3CON &= ~(1 << 3); // enable time3
    default:
        break;
    }
}

/**
 * @func   Timer0Overflow_ISR
 * @brief  None
 * @param  
 * @retval None
 */
void Timer0Overflow_ISR(void) interrupt 1
{
    if(p_timerCallBack != NULL)
    {
        p_timerCallBack();
    }
}