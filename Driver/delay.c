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
#include "delay.h"


/**
 * @func   delay_ms
 * @brief  None
 * @param  
 * @retval None
 */
void delay_ms (uint16_t value)
{
	while(value)
    {
        delay_us(1000);
        value--;
    };
}

/**
 * @func   delay_us
 * @brief  None
 * @param  
 * @retval None
 */
void delay_us (uint16_t value)
{
	register uint16_t loops =  (uint16_t)(dly_const * value) ;
    
    while(loops)
    {
        _nop_();
        loops--;
    };
}
