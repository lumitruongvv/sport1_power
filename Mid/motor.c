/*
 *  motor.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "motor.h"
#include "pwm.h"
#include "delay.h"

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/**
 * @func    MOTOR_Config
 * @brief   None
 * @param   None
 */
void MOTOR_Config(void)
{
    PWM_PinInit();
    delay_ms(500);
}
/**
 * @func    MOTOR_Init
 * @brief   None
 * @param   None
 */
void MOTOR_Init(uint16_t defaultDuty)
{
    PWM_Init();
    PWM_CreatedPeriodDuty(defaultDuty);
}
/**
 * @func    MOTOR_GetCurrentSpeed
 * @brief   None
 * @param   None
 */
uint16_t MOTOR_GetCurrentSpeed(uint8_t revSpeed)
{
    float x = revSpeed/10.0;
    return ((uint16_t)(13650 - 150*x));
}
/**
 * @func    MOTOR_SetSpeed
 * @brief   None
 * @param   None
 */
void MOTOR_SetSpeed(uint16_t currentDuty, uint16_t desireDuty)
{
    uint16_t i = 0;
    if(currentDuty >= desireDuty)
    {
        for(i = currentDuty; i >= desireDuty; i--)
        {
            PWM_CreatedPeriodDuty(i);
            delay_ms(10);
        }
    }else
    {
        for(i = currentDuty; i <= desireDuty; i++)
        {
            PWM_CreatedPeriodDuty(i);
            delay_ms(10);
        }
    }
}