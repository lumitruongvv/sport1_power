/*
 *  tick.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "timer.h"
#include "tick.h"

static uint32_t tick = 0;

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/**
 * @func   TICK_Init
 * @brief  None
 * @param  
 * @retval None
 */
void TICK_Init(void)
{
    TIMER_Init(TIMER0);
    TIMER_CallBackInit(TICK_Handle);
    TIMER_Enable(TIMER0);
}

/**
 * @func   TICK_Hanle
 * @brief  None
 * @param  
 * @retval None
 */
void TICK_Handle(void)
{
    tick++;
}
/**
 * @func   GET_CurrentTick
 * @brief  None
 * @param  
 * @retval None
 */
uint32_t GET_CurrentTick(void)
{
    return tick;
}

/**
 * @func   GET_LengthTime
 * @brief  None
 * @param  
 * @retval None
 */
uint32_t GET_LengthTime(uint32_t currentTick)
{
    uint32_t currentValue;
    currentValue = GET_CurrentTick();
    if(currentValue >= currentTick)
    {
        return (currentValue - currentTick);
    }
    return (currentValue + 0xFFFFFFFF - currentTick);
}

/**
 * @func   GET_LengthTimeExceed
 * @brief  None
 * @param  
 * @retval None
 */
uint8_t  GET_LengthTimeExceed(uint32_t startTime, uint32_t time_ms)
{
    if(GET_LengthTime(startTime) >= time_ms)
    {
        return 1;
    }
    return 0;
}