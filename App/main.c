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
#include "main_init.h"
#include "mainfunclist.h"

/**
 * @func   main
 * @brief  None
 * @param  
 * @retval None
 */
int main(void)
{
    MAIN_Init();
    while(1)
	{
        MAIN_Proc();
        funcHandle_AllFlag();
    }
}
