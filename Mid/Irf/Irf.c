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
#include "irf.h"
#include "uart.h"
#include "queue.h"
#include "xor.h"

QUEUEx_t    irf_CommandQueue;
irf_Command_t irf_CommandBuff[IRF_QUEUE_MAX];


/******************************************************************************/
/*                            FUNCTIONS                              */
/******************************************************************************/

/**
 * @func    IRF_Init
 * @brief   None
 * @param   None
 */
void IRF_Init(void)
{
    UART_Init(UART_Init);
    UART_CallBackInit(IRF_CallBackHandle);
    QUEUE_Init(&irf_CommandQueue, (u8*)irf_CommandBuff,\
                IRF_QUEUE_MAX, sizeof(irf_Command_t));
    UART_Enable();
}

/**
 * @func    IRF_CallBackHandle
 * @brief   None
 * @param   None
 */
static void IRF_CallBackHandle(void)
{
    static u8 revByte = 0;
    static u16 revByteCount = 0;
    u8 revBuff[IRF_HEADER + IRF_BUFF_MAX + 1];

    revByte = UART_RevData();
    revBuff[revByteCount++] = revByte;
    if(revByteCount >= IRF_HEADER)
    {
        if(revByteCount == (IRF_HEADER + revBuff[3] + 1))
        {
            if(revBuff[IRF_HEADER + revBuff[3]] == XOR_Caculator(revBuff, 0, IRF_HEADER + revBuff[3]))
            {
                QUEUE_Push(&irf_CommandQueue, revBuff);
            }
            revByteCount = 0;
        }
    }
}

/**
 * @func    IRF_Proc
 * @brief   None
 * @param   None
 */
void IRF_Proc(void)
{
    irf_Command_t irf_CommandBuff;
    if(!QUEUE_Empty(&irf_CommandQueue))
    {
        QUEUE_Get(&irf_CommandQueue, (u8*)&irf_CommandBuff);
        APP_CheckCommandExistAndExecutes(\
            irf_CommandBuff.command, irf_CommandBuff.type,\
            irf_CommandBuff.buff, irf_CommandBuff.length); 
    }
}

/**
 * @func    IRF_Send
 * @brief   None
 * @param   None
 */
void IRF_Send(u8* buff, u8 length)
{
    UART_SendData(buff, length);
}