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
#include "adc.h"

/**
 * @func   ADC_Init
 * @brief  None
 * @param  
 * @retval None
 */
void ADC_Init (void)
{
    P03_Input_Mode;
    ADCCON0 &= ~(1 << 7); // Clear Flag
    ADCCON1 |= (1 << 0); // Enable ADC
}

/**
 * @func   ADC_Read
 * @brief  None
 * @param  
 * @retval None
 */
uint16_t ADC_Read (uint8_t channel)
{
    uint16_t vruiAdcValueH = 0;
    uint8_t vruiAdcValueL = 0;
    uint16_t vruiAdcValue = 0;
    ADCCON0 &= ~(1 << 7); // Clear Flag
    AINDIDS |= (1 << channel); // Digital Input Disconnect P03
    ADCCON0 = ((ADCCON0 & 0xF0)|channel); // Select channel
    ADCCON0 |= (1 << 6); // Start converting
    while (!(ADCCON0 & (1 << 7)));
    vruiAdcValueH = (ADCRH >> 4)*256;
    vruiAdcValueL = (ADCRH << 4)|(ADCRL & 0x0F);
    vruiAdcValue = (uint16_t) (vruiAdcValueH + vruiAdcValueL);
    return vruiAdcValue;
}
