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
void delay_ms (uint16_t time_ms)
{
	while (time_ms)
	{
		CKCON |= (1 << 3); // clock source of Timer 0 is direct the system clock
		TL0 =  0x80;  // 1ms
		TH0 =  0xC1;  // 1ms
		TMOD |= (1 << 0); // timer0 16bit
		TCON |= (1 << 4); // enable timer0
		while(!(TCON & (1 << 5)));
		TCON &= ~((1 << 5)|(1 << 4)); // Clear TF0, disable timer0
		time_ms--;
	}
}

/**
 * @func   delay_us
 * @brief  None
 * @param  
 * @retval None
 */
void delay_us (uint16_t  time_us)
{
	while (time_us)
	{
		CKCON |= (1 << 3); // clock source of Timer 0 is direct the system clock
		TL0 =  0xF0;  // 1us
		TH0 =  0xFF;  // 1us
		TMOD |= (1 << 0); // timer0 16bit
		TCON |= (1 << 4); // enable timer0
		while(!(TCON & (1 << 5)));
		TCON &= ~((1 << 5)|(1 << 4)); // Clear TF0, disable timer0
		time_us--;
	}
}

/**
 * @func   delay_100us
 * @brief  None
 * @param  
 * @retval None
 */
void delay_100us (uint16_t time_us)
{
	while (time_us)
	{
		CKCON |= (1 << 3); // clock source of Timer 0 is direct the system clock
		TL0 =  0xC0;  // 100us
		TH0 =  0xF9;  // 100us
		TMOD |= (1 << 0); // timer0 16bit
		TCON |= (1 << 4); // enable timer0
		while(!(TCON & (1 << 5)));
		TCON &= ~((1 << 5)|(1 << 4)); // Clear TF0, disable timer0
		time_us--;
	}
}