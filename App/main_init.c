/*
 *      main_init.c
 *
 *      Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "tick.h"
#include "main_init.h"
#include "Irf.h"
#include "motor.h"
#include "relay.h"
#include "floor.h"

/******************************************************************************/
/*                              DECLARE                                      */
/******************************************************************************/

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/
/**
 * @func    main_Init
 * @brief   None
 * @param   None
 */
void MAIN_Init(void)
{
    MOTOR_Config();
    RELAY_Config();
    MOTOR_Init(DEFAULTSPEED);
    FLOOR_Init();
    TICK_Init();
    IRF_Init();
    ENABLE_AllInterrupt();
}

/**
 * @func    MAIN_Proc
 * @brief   None
 * @param   None
 */
void MAIN_Proc(void)
{
    IRF_Proc(); 
}