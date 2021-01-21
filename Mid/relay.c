/*
 *  relay.c
 *
 *  Created on: Dec 25, 2020
 *      Author: Truong VV
 */

#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "relay.h"

/******************************************************************************/
/*                              FUNCTION                                      */
/******************************************************************************/

/**
 * @func    RELAY_Config
 * @brief   None
 * @param   None
 */
void RELAY_Config (void)
{
    RELAYAC_Init();
    RELAYUP_Init();
    RELAYDOWN_Init();
    ResetBit(RELAY_AC_PORT, RELAY_AC_PIN);
    ResetBit(RELAY_UPDOWN_PORT, RELAY_UP_PIN);
    ResetBit(RELAY_UPDOWN_PORT, RELAY_DOWN_PIN);
}

/**
 * @func    RELAY_AC
 * @brief   None
 * @param   None
 */
void RELAY_AC(uint8_t state)
{
    if(state == ON)
    {
        SetBit(RELAY_AC_PORT, RELAY_AC_PIN);
    }else
    {
        ResetBit(RELAY_AC_PORT, RELAY_AC_PIN);
    }
    
}

/**
 * @func    RELAY_Up
 * @brief   None
 * @param   None
 */
void RELAY_Up(void)
{
    SetBit(RELAY_UPDOWN_PORT, RELAY_UP_PIN);
}

/**
 * @func    RELAY_UpReset
 * @brief   None
 * @param   None
 */
void RELAY_UpReset(void)
{
    ResetBit(RELAY_UPDOWN_PORT, RELAY_UP_PIN);
}

/**
 * @func    RELAY_Down
 * @brief   None
 * @param   None
 */
void RELAY_Down(void)
{
    SetBit(RELAY_UPDOWN_PORT, RELAY_DOWN_PIN);
}

/**
 * @func    RELAY_DownReset
 * @brief   None
 * @param   None
 */
void RELAY_DownReset(void)
{
    ResetBit(RELAY_UPDOWN_PORT, RELAY_DOWN_PIN);
}
