/*
 * Copyright (c) 2021
 * Team, JSC.
 * All Rights Reserved
 *
 *
 * Description:
 *
 * Author: Truongvv
 *
 * Last Changed By:  $Author: Truongvv $
 * Revision:         $Revision: 1.0 $
 * Last Changed:     $Date: x/x/xxxx $
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "pwm.h"
#include "delay.h"
/**
 * @func   PWM_Init
 * @brief  None
 * @param  
 * @retval None
 */
void PWM_Init (void)
{
    PIOCON0 |= (1 << 2);    // P10 is pin PWM output
    PWMCON0 |= (1 << 4);    // Clear PWM 16BIT COUNTER
    CKCON   &= ~(1 << 6);   // Clock PWM is Clock SYS
    PWMCON1 |= (1 << 2);    // DIV Clock 16 = 1M
}
	

/**
 * @func   PWM_CreatedPeriodDuty
 * @brief  None
 * @param  
 * @retval None
 */
void PWM_CreatedPeriodDuty (uint16_t pwmDuty)
{
    uint16_t vruiPwmDuty;
    PWMCON0 &= ~(1 << 7);
    vruiPwmDuty = (uint16_t) pwmDuty;
    PWMPL = 0x98;
    PWMPH = 0x3A; //      15khz
    PWM2H = vruiPwmDuty >> 8; // DUTY 
    PWM2L = (vruiPwmDuty - PWM1H*256);
    PWMCON0 |= (1 << 7); // Start run
}

/**
 * @func   PWM_Stop
 * @brief  None 
 * @param  
 * @retval None
 */
void PWM_Stop(uint16_t pwmDuty)
{
	uint16_t i;
    for(i = pwmDuty; i <= 15000; i=i+100)
    {
        PWM_CreatedPeriodDuty(i);
        delay_ms(100);		  
    }
}

/**
 * @func   PWM_Start
 * @brief  None
 * @param  
 * @retval None
 */
void PWM_Start(uint16_t pwmDuty)
{
	uint16_t i;
    for(i = 15000; i > pwmDuty; i=i-100)
    {
        PWM_CreatedPeriodDuty(i);
        delay_ms(100);		  
    }

}
